/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:54:31 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/15 11:30:18 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_image *img, int start_x, int start_y,
	int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_pixel(img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_tile(t_game *game, int x, int y, char tile)
{
	int	color;

	color = 0x000000;
	if (tile == '1')
		color = 0x808080;
	else if (tile == '0')
		color = 0x202020;
	else if (tile == 'N' || tile == 'S'
		|| tile == 'E' || tile == 'W')
		color = 0x202020;
	else
		return;
	draw_square(&game->image,
		x * 64,
		y * 64,
		64,
		color);
}

void	draw_map_2d(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_tile(game, x, y, game->map.grid[y][x]);
			x++;
		}
		y++;
	}
}

void	draw_player_direction(t_game *game)
{
	int	i;
	int	start_x;
	int	start_y;
	int	x;
	int	y;

	start_x = (int)(game->player.x * 64);
	start_y = (int)(game->player.y * 64);

	i = 0;
	while (i < 64)
	{
		x = start_x + (int)(game->player.dir_x * i);
		y = start_y + (int)(game->player.dir_y * i);
		put_pixel(&game->image, x, y, 0xFF0000);
		i++;
	}
}
