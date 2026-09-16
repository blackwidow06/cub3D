/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 08:15:25 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/15 13:04:31 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count_map_lines(int fd, t_map *map)
{
	char	*line;
	int		in_map;

	in_map = 0;
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
	return (0);
}

static int	read_map_file(int fd, t_map *map)
{
	int		i;
	int		in_map;
	char	*line;

	i = 0;
	in_map = 0;
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
	return (0);
}

static int	fill_map_grid(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	if (read_map_file(fd, map) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	read_map_grid(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	if (count_map_lines(fd, map) == 1)
		return (1);
	close(fd);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (map->grid == NULL)
		return (1);
	if (fill_map_grid(filename, map) == 1)
		return (1);
	map->width = get_map_width(map);
	return (0);
}
