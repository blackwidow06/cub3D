/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 09:45:29 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/14 12:45:55 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parse_textures(char **texture, char *line)
{
	if (*texture != NULL)
	{
		printf("Error\nDuplicate texture\n");
		return (1);
	}
	if (line[3] == '\0')
	{
		printf("Error\nEmpty texture path\n");
		return (1);
	}
	*texture = ft_strdup(line + 3);
	if (*texture == NULL)
		return (1);
	return (0);
}

static int	parse_line(char *line, t_texture *texture)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (parse_textures(&texture->north, line));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (parse_textures(&texture->south, line));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (parse_textures(&texture->west, line));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (parse_textures(&texture->east, line));
	else if (ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0)
		return (parse_colors(texture, line));
	return (0);
}

int	read_map(char *filename, t_texture *texture)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		remove_newline(line);
		if (parse_line(line, texture) != 0)
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
