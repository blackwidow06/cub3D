/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:37:02 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/25 09:45:08 by malavaud         ###   ########.fr       */
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

//void	draw_column(t_game *game, int x)
//{
//	t_ray	*ray;
//	int		y;
//	int		texture_x;
//	int		texture_y;
//	double	step;
//	double	tex_pos;

//	ray = &game->ray;
//	texture_x = get_texture_x(game);
//	step = (double)game->wall_texture.height / ray->line_height;
//	tex_pos = (ray->draw_start - WIN_HEIGHT / 2
//			+ ray->line_height / 2) * step;
//	y = 0;
//	while (y < WIN_HEIGHT)
//	{
//		if (y < ray->draw_start)
//			put_pixel(&game->image, x, y, game->ceiling_rgb);
//		else if (y <= ray->draw_end)
//		{
//			texture_y = (int)tex_pos
//				% game->wall_texture.height;
//			tex_pos += step;
//			put_pixel(&game->image, x, y,
//				get_texture_pixel(&game->wall_texture,
//					texture_x, texture_y));
//		}
//		else
//			put_pixel(&game->image, x, y, game->floor_rgb);
//		y++;
//	}
//}
void	draw_column(t_game *game, int x)
{
	t_ray	*ray;
	t_image	*texture;
	int		y;
	int		texture_x;
	int		texture_y;
	double	step;
	double	tex_pos;

	ray = &game->ray;
	texture = get_wall_texture(game);
	texture_x = get_texture_x(game);
	step = (double)texture->height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * step;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < ray->draw_start)
			put_pixel(&game->image, x, y, game->ceiling_rgb);
		else if (y <= ray->draw_end)
		{
			texture_y = (int)tex_pos % texture->height;
			tex_pos += step;
			put_pixel(&game->image, x, y,
				get_texture_pixel(texture, texture_x, texture_y));
		}
		else
			put_pixel(&game->image, x, y, game->floor_rgb);
		y++;
	}
}
