/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:04:44 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/23 14:14:19 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	color_translation(char	*color)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	rgb = ft_split(color, ',');
	if (rgb == NULL)
		return (1);
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	free_split(rgb, 3);
	return ((red << 16) | (green << 8) | blue);
}

int	parse_color(t_game *game)
{
	game->floor_rgb = color_translation(game->texture.floor);
	if (!game->floor_rgb)
		return (1);
	game->ceiling_rgb = color_translation(game->texture.ceiling);
	if (!game->ceiling_rgb)
		return (1);
	return (0);
}
