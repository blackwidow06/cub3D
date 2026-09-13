/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 13:53:39 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/13 12:45:47 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	parsing(char *filename, t_texture *texture, t_game *game)
{
	/* check le file name*/
	if (check_map_file(filename) != 0)
		exit_game(game, "Error\n file .cub invalid\n");
	/* on read la map */
	if (read_map(filename, texture) != 0)
		exit_game(game, "Error\n Invalid read map\n");
	/* on check les textures apres les avoir rangees*/
	if (check_textures(texture) != 0)
		exit_game(game, "Error\n Invalid texture\n");
	return (0);
}