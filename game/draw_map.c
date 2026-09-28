/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:54:31 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/25 17:23:29 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 720)
	{
		if (y < 720 / 2)
			color = game->ceiling_rgb;
		else
			color = game->floor_rgb;
		x = 0;
		while (x < 1280)
		{
			put_pixel(&game->image, x, y, color);
			x++;
		}
		y++;
	}
}
