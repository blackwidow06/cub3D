/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:07:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/18 11:45:35 by malavaud         ###   ########.fr       */
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

int	init_dda(t_game *game)
{
	t_ray		*ray;
	t_player	*player;

	ray = &game->ray;
	player = &game->player;
	
}