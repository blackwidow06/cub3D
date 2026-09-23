/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2026/09/20 14:34:18 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/20 16:31:22 by mrojouan         ###   ########.fr       */
=======
/*   Created: 2026/09/15 10:41:58 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/22 08:52:34 by malavaud         ###   ########.fr       */
>>>>>>> b98c1075e3a270a6a987a4942306b85ed986d092
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_char_around(t_map *map, int i, int j)
{
	int	len;

	if (j == 0 || !is_valid_cell(map->grid[i][j - 1]))
		return (1);
	len = ft_strlen(map->grid[i]);
	if (j + 1 >= len || !is_valid_cell(map->grid[i][j + 1]))
		return (1);
	if (i == 0 || j >= (int)ft_strlen(map->grid[i - 1])
		|| !is_valid_cell(map->grid[i - 1][j]))
		return (1);
	if (map->grid[i + 1] == NULL
		|| j >= (int)ft_strlen(map->grid[i + 1])
		|| !is_valid_cell(map->grid[i + 1][j]))
		return (1);
	return (0);
}

static int	check_inside(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i] != NULL)
	{
		j = 0;
		while (map->grid[i][j] != '\0')
		{
			if (map->grid[i][j] == '0'
				|| map->grid[i][j] == 'N'
				|| map->grid[i][j] == 'S'
				|| map->grid[i][j] == 'E'
				|| map->grid[i][j] == 'W')
			{
				if (check_char_around(map, i, j) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_top_bottom(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[0][i] != '\0')
	{
		if (map->grid[0][i] != '1' && map->grid[0][i] != ' ')
			return (1);
		i++;
	}
	i = 0;
	while (map->grid[map->height - 1][i] != '\0')
	{
		if (map->grid[map->height - 1][i] != '1'
				&& map->grid[map->height - 1][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	check_sides(t_map *map)
{
<<<<<<< HEAD
	int	i;
	int	j;
	int	len;

	i = 0;
	while (map->grid[i] != NULL)
	{
		j = 0;
		len = ft_strlen(map->grid[i]);
		while (map->grid[i][j] == ' ')
			j++;
		if (map->grid[i][j] == '\0' || map->grid[i][j] != '1')
			return (1);
		j = len - 1;
		while (j >= 0 && map->grid[i][j] == ' ')
			j--;
		if (j < 0 || map->grid[i][j] != '1')
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
	if (check_inside(map) == 1)
		return (1);
	return (0);
=======
    if (check_top_bottom(map) == 1)
        return (1);
    if (check_sides(map) == 1)
        return (1);
    return (0);
>>>>>>> b98c1075e3a270a6a987a4942306b85ed986d092
}
