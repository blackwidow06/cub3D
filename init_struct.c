/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 12:44:54 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/29 10:31:04 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	init_image(t_image *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->byte_order = 0;
	image->width = 0;
	image->height = 0;
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
}

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->move_speed = 0.03;
	player->rot_speed = 0.02;
}

void	init_texture(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->ceiling = NULL;
	texture->floor = NULL;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->floor_rgb = 0;
	game->ceiling_rgb = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_s = 0;
	game->key_w = 0;
	game->key_left = 0;
	game->key_right = 0;
	init_player(&game->player);
	init_texture(&game->texture);
	init_image(&game->image);
	init_image(&game->wall_texture);
	init_image(&game->wall_north);
	init_image(&game->wall_south);
	init_image(&game->wall_east);
	init_image(&game->wall_west);
	init_map(&game->map);
	init_ray_struct(&game->ray);
}
