/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:49:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/14 13:34:38 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game		game;

 	if (argc != 2)
 		return (1);
 	init_texture(&game.textures);		
 	init_game(&game);
 	parsing(argv[1], &game);
	open_game(&game);
 	free(game.textures.north);
 	free(game.textures.south);
 	free(game.textures.west);
 	free(game.textures.east);
 	return (0);
}
