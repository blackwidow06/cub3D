/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:49:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/15 12:57:13 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int    key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game, "Exit game\n");
    return (0);
}

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

int	main(int argc, char **argv)
{
	t_texture	texture;
	t_game		game;

 	if (argc != 2)
 		return (1);
	init_game(&game);
	init_texture(&game.texture);		
	init_player(&game.player);
 	parsing(argv[1], &game);
 	free(texture.north);
 	free(texture.south);
 	free(texture.west);
 	free(texture.east);
 	return (0);
}
