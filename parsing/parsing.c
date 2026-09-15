/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:11:43 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/15 12:37:20 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(char *filename, t_game *game)
{
	t_map	map;

	map.grid = NULL;
	if (check_map_file(filename) != 0)
		exit_game(game, "Error\nfile .cub invalid\n");
	if (read_map(filename, &game->textures) != 0)
		exit_game(game, "Error\nInvalid color\n");
	if (check_textures(&game->textures) != 0)
		exit_game(game, "Error\nInvalid texture\n");
	if (check_all_colors(&game->textures) != 0)
		exit_game(game, "Error\nInvalid color\n");
	if (read_map_grid(filename, &map) != 0)
		exit_game(game, "Error\nInvalid map\n");
	if (check_map_characters(&map) != 0)
		exit_game(game, "Error\nInvalid map characters\n");
	if (check_player_count(&map) != 0)
		exit_game(game, "Error\nInvalid player count\n");
	if (check_map_walls(&map) != 0)
		exit_game(game, "Error\nMap not closed\n");
	return (0);
}
