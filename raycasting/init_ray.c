/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:07:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/22 10:50:26 by malavaud         ###   ########.fr       */
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

int	init_ray(t_game *game, int x)
{
	game->ray.camera_x = 2 * x / (double)WIN_WIDTH - 1; /*transforme la colonne x en -1 ou 1*/
	game->ray.ray_dir_x = game->player.dir_x /*calcul direction du rayon*/
		+ game->player.plane_x * game->ray.camera_x;
	game->ray.ray_dir_y = game->player.dir_y
		+ game->player.plane_y * game->ray.camera_x;
}

int	init_dda(t_game *game) /*avancer de case en case until wall*/
{
	t_ray		*ray;
	t_player	*player;

	ray = &game->ray;
	player = &game->player;
	ray->map_x = (int)player->x; /*find case actuelle*/
	ray->map_y = (int)player->y;
	ray->delta_dist_y = fabs(1 / ray->ray_dir_x);/*distane pour traverser une case complete*/
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y); /*fabs pour obtenir une valeur positive*/
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;/*rayon gauche*/
		ray->side_dist_x = (player->x - ray->map_x)
			* ray->delta_dist_x;/*distance until la frontiere*/
	}
	else
	{
		ray->step_x = 1;/*rayon droite*/
		ray->side_dist_x = (ray->map_x + 1.0 - player->x)
			* ray->delta_dist_x;/*distance until la frontiere*/
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

//static int	is_wall(t_game *game, t_ray *ray)
//{
//	if (ray->map_y < 0
//		|| ray->map_y >= game->map.height)
//		return (1);
//	if (ray->map_x < 0
//		|| ray->map_x >= (int)ft_strlen(game->map.grid[ray->map_y]))
//		return (1);
//	if (game->map.grid[ray->map_y][ray->map_x] == '1')
//		return (1);
//	return (0);
//}

void	single_ray(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	ray->side = 0;
	while (!is_wall(game, ray))
	{
		if (ray->side_dist_x < ray->side_dist_y) /*quelle frontiere est plus proche*/
		{
			ray->side_dist_x += ray->delta_dist_x;/*si x est plus proche change de colonne*/
			ray->map_x += ray->step_x;
			ray->side = 0;/*verticale*/
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;/*si y est plus proche change de ligne*/
			ray->map_x += ray->step_y;
			ray->side = 1;/*horizontale*/
		}
	}
}

void	calculate_wall(t_game *game)
{
	t_ray *ray;

	ray = &game->ray;
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x
			- ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y
			- ray->delta_dist_y;
	ray->line_height = (int)(WIN_HEIGHT
			/ ray->delta_dist_y);
	ray->draw_start = -ray->line_height / 2
			+ WIN_HEIGHT /2;
	if (ray->draw_start < 0)
		ray->draw_start < 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	draw_column(t_game *game, int x)
{
	
}