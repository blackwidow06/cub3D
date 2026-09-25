/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:30:50 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/25 13:25:38 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key_w = 0;
	else if (keycode == 115)
		game->key_s = 0;
	else if (keycode == 97)
		game->key_a = 0;
	else if (keycode == 100)
		game->key_d = 0;
	else if (keycode == KEY_LEFT)
		game->key_left = 0;
	else if (keycode == KEY_RIGHT)
		game->key_right = 0;
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == 119)
		game->key_w = 1;
	else if (keycode == 115)
		game->key_s = 1;
	else if (keycode == 97)
		game->key_a = 1;
	else if (keycode == 100)
		game->key_d = 1;
	else if (keycode == KEY_LEFT)
		game->key_left = 1;
	else if (keycode == KEY_RIGHT)
		game->key_right = 1;
	return (0);
}

static int	init_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx, 1280, 720, "Cub3D");
	if (!game->window)
		return (1);
	game->image.img = mlx_new_image(game->mlx, 1280, 720);
	game->image.addr = mlx_get_data_addr(
			game->image.img,
			&game->image.bits_per_pixel,
			&game->image.line_length,
			&game->image.byte_order);
	draw_background(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->image.img, 0, 0);
	return (0);
}

int	open_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	if (load_wall_textures(game))
		return (1);
	if (init_window(game))
		return (1);
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
