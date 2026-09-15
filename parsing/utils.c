/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:29:13 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/15 12:17:21 by malavaud         ###   ########.fr       */
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
