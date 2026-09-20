/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:29:13 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/20 16:28:06 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

void	remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
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
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	get_map_width(t_map *map)
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
