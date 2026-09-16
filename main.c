/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:49:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/16 10:54:55 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//int	main(void)
//{
//	t_game game;
	
//	game.mlx = mlx_init();
//	if (!game.mlx)
//		return (1);
//	game.window = mlx_new_window(game.mlx, 800, 600, "Cub3D");
//	if (!game.window)
//		return (1);
//	mlx_hook(game.window, 17, 0, exit_game, &game);
//	mlx_hook(game.window, 2, 1L << 0, key_press, &game);
//	mlx_loop(game.mlx);
//	return (0);
//}

int    main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
		return (1);
	init_texture(&game.texture);
	init_map(&game.map);
	init_game(&game);
	parsing(argv[1], &game);
	free(game.texture.north);
	free(game.texture.south);
	free(game.texture.west);
	free(game.texture.east);
	return (0);
}
