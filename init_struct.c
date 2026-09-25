/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 12:44:54 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/25 17:15:38 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->key_a = 0;
	game->key_d = 0;
	game->key_s = 0;
	game->key_w = 0;
	game->key_left = 0;
	game->key_right = 0;
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
