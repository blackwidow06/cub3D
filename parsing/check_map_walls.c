/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:41:58 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/15 10:42:28 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map_walls(t_map *map)
{
	int	i;
	int	j;
	int	len;

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
	i = 0;
	while (map->grid[i] != NULL)
	{
		len = ft_strlen(map->grid[i]);
		if (map->grid[i][0] != '1')
			return (1);
		j = len - 1;
		if (map->grid[i][j] != '1')
			return (1);
		if (i > 0 && len > (int)ft_strlen(map->grid[i - 1]))
			return (1);
		if (map->grid[i + 1] != NULL
			&& len > (int)ft_strlen(map->grid[i + 1]))
			return (1);
		i++;
	}
	return (0);
}
