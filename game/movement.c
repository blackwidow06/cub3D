/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:44:58 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/15 11:29:44 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;

	if (map_x < 0 || map_y < 0)
		return (1);
	if (map_y >= game->map.height)
		return (1);
	if (map_x >= (int)ft_strlen(game->map.grid[map_y]))
		return (1);
	if (game->map.grid[map_y][map_x] == '1')
		return (1);
	return (0);
}

void move_forward_backward(t_game *game, double direction)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x
		+ game->player.dir_x * game->player.move_speed * direction;
	new_y = game->player.y
		+ game->player.dir_y * game->player.move_speed * direction;
	if (!is_wall(game, new_x, game->player.y))
		game->player.x = new_x;
	if (!is_wall(game, game->player.x, new_y))
		game->player.y = new_y;
}

void move_left_right(t_game *game, double direction)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x
		+ (-game->player.dir_y)
		* game->player.move_speed * direction;
	new_y = game->player.y
		+ game->player.dir_x
		* game->player.move_speed * direction;

	if (!is_wall(game, new_x, game->player.y))
		game->player.x = new_x;
	if (!is_wall(game, game->player.x, new_y))
		game->player.y = new_y;
}

void rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);

	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
}
