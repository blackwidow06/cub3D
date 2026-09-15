/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 08:15:25 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/15 10:39:08 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_map_width(t_map *map)
{
	int	i;
	int	len;
	int	width;

	i = 0;
	width = 0;
	while (map->grid[i] != NULL)
	{
		len = ft_strlen(map->grid[i]);
		if (len > width)
			width = len;
		i++;
	}
	return (width);
}

static	int	fill_map_grid(char *filename, t_map *map)
{
	int		fd;
	int		i;
	int		in_map;
	char	*line;

	in_map = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		remove_newline(line);
		if (is_map_line(line) == 1)
			in_map = 1;
		if (in_map == 1)
		{
			map->grid[i] = ft_strdup(line);
			if (map->grid[i] == NULL)
				return (1);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	close(fd);
	return (0);
}

int	read_map_grid(char *filename, t_map *map)
{
	int		fd;
	int		in_map;
	char	*line;
	
	in_map = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		remove_newline(line);
		if (is_map_line(line) == 1)
			in_map = 1;
		if (in_map == 1)
			map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (map->grid == NULL)
		return (1);
	if (fill_map_grid(filename, map) != 0)
		return (1);
	map->width = get_map_width(map);
	return (0);
}
