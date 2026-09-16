/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:30:50 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/16 15:39:15 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, "Exit game");
	if (keycode == 1731)
		move_forward_backward(game, 1);
	if (keycode == 1753)
		move_forward_backward(game, -1);
	if (keycode == 1734)
		move_left_right(game, -1);
	if (keycode == 1751)
		move_left_right(game, 1);
	if (keycode == KEY_LEFT)
		rotate_player(game, -game->player.rot_speed);
	if (keycode == KEY_RIGHT)
		rotate_player(game, game->player.rot_speed);
	draw_map_2d(game);
	draw_player_direction(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->image.img, 0, 0);
	return (0);
}

int	open_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->window = mlx_new_window(game->mlx, 1280, 720, "Cub3D");
	if (!game->window)
		return (1);
	game->image.img = mlx_new_image(game->mlx, 1280, 720);
	game->image.addr = mlx_get_data_addr(
			game->image.img,
			&game->image.bits_per_pixel,
			&game->image.line_length,
			&game->image.endian);
	draw_map_2d(game);
	draw_player_direction(game);
	mlx_put_image_to_window(
		game->mlx,
		game->window,
		game->image.img,
		0,
		0);
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_loop(game->mlx);
	return (0);
}
