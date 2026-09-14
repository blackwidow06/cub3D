/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 09:45:29 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/14 09:48:20 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parse_textures(char **texture, char *line) /*pas de textures doublon*/
{
	if (*texture != NULL)
		return (1);
	if (line[3] == '\0')
		return (1);
	*texture = ft_strdup(line + 3);
	if (*texture == NULL)
		return (1);
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
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			if (parse_textures(&texture->north, line) != 0)
			{
				free(line);
				close(fd);
				return (1);
			}
		}
		else if (ft_strncmp(line, "SO ", 3) == 0)
		{
			if (parse_textures(&texture->south, line) != 0)
			{
				free(line);
				close(fd);
				return (1);
			}
		}
		else if (ft_strncmp(line, "WE ", 3) == 0)
		{
			if (parse_textures(&texture->west, line) != 0)
			{
				free(line);
				close(fd);
				return (1);
			}
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			if (parse_textures(&texture->east, line) != 0)
			{
				free(line);
				close(fd);
				return (1);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
