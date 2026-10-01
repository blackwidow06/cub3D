/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:04:44 by mrojouan          #+#    #+#             */
/*   Updated: 2026/10/01 16:20:39 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	color_translation(char	*color)
{
	char	**rgb;
	char	*curr;
	int		red;
	int		green;
	int		blue;

	rgb = ft_split(color, ',');
	if (rgb == NULL)
		return (1);
	curr = skip_spaces(rgb[0]);
	red = ft_atoi(curr);
	curr = skip_spaces(rgb[1]);
	green = ft_atoi(curr);
	curr = skip_spaces(rgb[2]);
	blue = ft_atoi(curr);
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
