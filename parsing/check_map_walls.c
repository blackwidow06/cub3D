/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:41:58 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/16 09:00:11 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int	check_top_bottom(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[0][i] != '\0')
	{
		if (map->grid[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map->grid[map->height - 1][i] != '\0')
	{
		if (map->grid[map->height - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_extra_walls(char *line, char *other)
{
	int	i;
	int	len;

	i = ft_strlen(other);
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_sides(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (map->grid[i] != NULL)
	{
		len = ft_strlen(map->grid[i]);
		if (len == 0 || map->grid[i][0] != '1')
			return (1);
		if (map->grid[i][len - 1] != '1')
			return (1);
		if (i > 0
			&& check_extra_walls(map->grid[i], map->grid[i - 1]) != 0)
			return (1);
		if (map->grid[i + 1] != NULL
			&& check_extra_walls(map->grid[i], map->grid[i + 1]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_map_walls(t_map *map)
{
	if (check_top_bottom(map) == 1)
		return (1);
	if (check_sides(map) == 1)
		return (1);
	return (0);
}
