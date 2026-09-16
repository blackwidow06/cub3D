/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:28:45 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/16 11:36:49 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int	is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_map_characters(t_map *map)
{
	int    i;
	int    j;

	i = 0;
	while (map->grid[i] != NULL)
	{
		j = 0;
		while (map->grid[i][j] != '\0')
		{
			if (is_valid_map_char(map->grid[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static	int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_player_count(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->grid[i] != NULL)
	{
		j = 0;
		while (map->grid[i][j] != '\0')
		{
			if (is_player(map->grid[i][j]) == 1)
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
				&& line[i] != 'N' && line[i] != 'S'
				&& line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}
