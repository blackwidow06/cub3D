/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 09:47:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/14 09:50:07 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map_file(char *filename)
{
	int len;
	int	fd;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	close (fd);
	return (0);
}

static	int	check_texture_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

static int	check_texture_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (1);
	if (ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		printf("Error : textures must be .xpm\n");
		return (1);
	}
	return (0);
}

void	remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	check_textures(t_texture *texture)
{
	if (texture->north == NULL)
		return (1);
	if (texture->south == NULL)
		return (1);
	if (texture->west == NULL)
		return (1);
	if (texture->east == NULL)
		return (1);
	if (check_texture_extension(texture->north) != 0)
		return (1);
	if (check_texture_file(texture->north) != 0)
		return (1);
	if (check_texture_extension(texture->south) != 0)
		return (1);
	if (check_texture_file(texture->south) != 0)
		return (1);
	if (check_texture_extension(texture->west) != 0)
		return (1);
	if (check_texture_file(texture->west) != 0)
		return (1);
	if (check_texture_extension(texture->east) != 0)
		return (1);
	if (check_texture_file(texture->east) != 0)
		return (1);
	return (0);
}
