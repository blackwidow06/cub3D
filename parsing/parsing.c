/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:11:43 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/14 13:05:26 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(char *filename, t_texture *texture, t_game *game)
{
	if (check_map_file(filename) != 0)
		exit_game(game, "Error\nfile .cub invalid\n");
	if (read_map(filename, texture) != 0)
		exit_game(game, "Error\nInvalid color\n");
	if (check_textures(texture) != 0)
		exit_game(game, "Error\nInvalid texture\n");
	if (check_all_colors(texture) != 0)
		exit_game(game, "Error\nInvalid color\n");
	return (0);
}
