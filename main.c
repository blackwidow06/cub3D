/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:49:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/28 13:16:39 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	init_texture(&game.texture);
	init_player(&game.player);
	init_map(&game.map);
	init_game(&game);
	if (parsing(argv[1], &game))
		print_error_exit(&game, "A LAIDE LE PARSING");
	if (!open_game(&game))
		print_error_exit(&game, "A LAIDE LE OPEN"); /* tu peux le repasser en commentaire pour tes tests*/
	return (0);
}
