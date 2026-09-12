/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:49:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/12 13:16:17 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int    key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
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

//int	main(int argc, char **argv)
//{
//	if (argc != 2)
//		return (1);
//	read_map(argv[1]);
//	return (0);
//}

int	main(int argc, char **argv)
{
	t_texture	texture;

	if (argc != 2)
		return (1);
	if (check_map_file(argv[1]) != 0)
	{
		printf("Error : file .cub invalid\n");
		return (1);	
	}
	texture.north = NULL;
	texture.south = NULL;
	texture.west = NULL;
	texture.east = NULL;
	texture.ceiling = NULL;
	texture.floor = NULL;
	if (read_map(argv[1], &texture) != 0)
		return (1);
	if (check_textures(&texture) != 0)
	{
		printf("Error : invalid texture\n");
		return (1);
	}
	printf("Nord : %s", texture.north);
	printf("Sud : %s", texture.south);
	printf("Ouest : %s", texture.west);
	printf("Est : %s", texture.east);
	free(texture.north);
	free(texture.south);
	free(texture.west);
	free(texture.east);
	return (0);
}