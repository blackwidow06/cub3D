/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:11:43 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/14 11:27:53 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(char *filename, t_texture *texture, t_game *game)
{
	if (check_map_file(filename) != 0)
		exit_game(game, "Error\nfile .cub invalid\n");
	if (read_map(filename, texture) != 0)
		exit_game(game, NULL);
	if (check_textures(texture) != 0)
		exit_game(game, "Error\nInvalid texture\n");
	return (0);
}