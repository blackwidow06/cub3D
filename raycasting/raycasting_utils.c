/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:37:02 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/23 12:41:09 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_map_wall(t_game *game, t_ray *ray)
{
	if (ray->map_y < 0
		|| ray->map_y >= game->map.height)
		return (1);
	if (ray->map_x < 0
		|| ray->map_x >= (int)ft_strlen(game->map.grid[ray->map_y]))
		return (1);
	if (game->map.grid[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

void	single_ray(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	ray->side = 0;
	while (!is_map_wall(game, ray))
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
			ray->map_y += ray->step_y;
			ray->side = 1;/*horizontale*/
		}
	}
}

void	calculate_wall(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	if (ray->side == 0) /*calculer distance du mur x ou y*/
		ray->perp_wall_dist = ray->side_dist_x
			- ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y
			- ray->delta_dist_y;
	if (ray->perp_wall_dist <= 0)
		ray->perp_wall_dist = 0.1;
	ray->line_height = (int)(WIN_HEIGHT /*calcul hauteur de la colonne*/
			/ ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2
		+ WIN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2
		+ WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_HEIGHT)/*limite pour pas dessiner hors de l'ecran*/
		ray->draw_end = WIN_HEIGHT - 1;
}

void	draw_column(t_game *game, int x)
{
	int	y;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < game->ray.draw_start)
			color = 0x87CEEB;
		else if (y <= game->ray.draw_end)
			color = 0x808080;
		else
			color = 0x654321;
		put_pixel(&game->image, x, y, color);
		y++;
	}
}
