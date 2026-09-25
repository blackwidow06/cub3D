/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:54:31 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/25 09:44:16 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

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
		return ;
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

int	get_texture_pixel(t_image *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

int	get_texture_x(t_game *game)
{
	t_image	*texture;
	double	wall_x;
	int		texture_x;

	texture = get_wall_texture(game);
	if (game->ray.side == 0)
		wall_x = game->player.y
			+ game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		wall_x = game->player.x
			+ game->ray.perp_wall_dist * game->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * texture->width);
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
		texture_x = texture->width - texture_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir_y < 0)
		texture_x = texture->width - texture_x - 1;
	return (texture_x);
}

t_image	*get_wall_texture(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x > 0)
			return (&game->wall_west);
		return (&game->wall_east);
	}
	if (game->ray.ray_dir_y > 0)
		return (&game->wall_north);
	return (&game->wall_south);
}
