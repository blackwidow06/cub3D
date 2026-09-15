/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:11:43 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/15 12:47:01 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(char *filename, t_game *game)
{
	if (check_map_file(filename) != 0)
		exit_game(game, "Error\nfile .cub invalid\n");
	if (read_map(filename, &game->texture) != 0)
		exit_game(game, "Error\nInvalid color\n");
	if (check_textures(&game->texture) != 0)
		exit_game(game, "Error\nInvalid texture\n");
	if (check_all_colors(&game->texture) != 0)
		exit_game(game, "Error\nInvalid color\n");
	if (read_map_grid(filename, &game->map) != 0)
		exit_game(game, "Error\nInvalid map\n");
	if (check_map_characters(&game->map) != 0)
		exit_game(game, "Error\nInvalid map characters\n");
	if (check_player_count(&game->map) != 0)
		exit_game(game, "Error\nInvalid player count\n");
	if (check_map_walls(&game->map) != 0)
		exit_game(game, "Error\nMap not closed\n");
	return (0);
}
