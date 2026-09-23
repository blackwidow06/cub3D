/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:07:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/23 15:22:37 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(game, x);
		init_dda(game);
		single_ray(game);
		calculate_wall(game);
		draw_column(game, x);
		if (x == WIN_WIDTH / 2)
		{
			printf("Ray dir X : %f\n", game->ray.ray_dir_x);
			printf("Ray dir Y : %f\n", game->ray.ray_dir_y);
			printf("Wall distance : %f\n",
				game->ray.perp_wall_dist);
		}
		x++;
	}
}

int	game_loop(t_game *game)
{
	if (game->key_w)
		move_forward_backward(game, 1);
	if (game->key_s)
		move_forward_backward(game, -1);
	if (game->key_a)
		move_left_right(game, -1);
	if (game->key_d)
		move_left_right(game, 1);
	if (game->key_left)
		rotate_player(game, -game->player.rot_speed);
	if (game->key_right)
		rotate_player(game, game->player.rot_speed);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->image.img, 0, 0);
	return (0);
}
