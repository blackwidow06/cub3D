/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:04:44 by mrojouan          #+#    #+#             */
/*   Updated: 2026/11/12 13:04:21 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	color_translation(char *color, int *result)
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
	*result = (red << 16) | (green << 8) | blue;
	return (0);
}

int	parse_color(t_game *game)
{
	if (color_translation(game->texture.floor, &game->floor_rgb) != 0)
		return (1);
	if (color_translation(game->texture.ceiling, &game->ceiling_rgb) != 0)
		return (1);
	return (0);
}
