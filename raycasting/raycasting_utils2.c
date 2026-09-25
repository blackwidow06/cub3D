/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:40:06 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/25 08:45:45 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//-1 = gauche 0 = millieu 1 = droite
//si WIN_WIDTH = 1280
//x = 640 (millieu)
//camera_x = 2 * 640 / 1280 -1
//camera_x = 0
//donc le rayon direction joueur au millieu

//calcul du rayon si joueur = N
//camera_x = 0
//ray_dir_x = 0 + 0.66 * 0 = 0
//ray_dir_y = -1 + 0 * 0 = -1   -> donc millieu

void	init_ray(t_game *game, int x)
{
	game->ray.camera_x = 2 * x / (double)WIN_WIDTH - 1; /*transforme la colonne x en -1 ou 1*/
	game->ray.ray_dir_x = game->player.dir_x /*calcul direction du rayon*/
		+ game->player.plane_x * game->ray.camera_x;
	game->ray.ray_dir_y = game->player.dir_y
		+ game->player.plane_y * game->ray.camera_x;
}

static void	init_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	init_side_dist(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y)
			* ray->delta_dist_y;
	}
}

void	init_dda(t_game *game)
{
	t_ray		*ray;
	t_player	*player;

	ray = &game->ray;
	player = &game->player;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	init_delta_dist(ray);
	init_side_dist(ray, player);
}
