/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:07:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/23 12:38:38 by malavaud         ###   ########.fr       */
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
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->image.img, 0, 0);
	return (0);
}
