/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:49:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/12 10:31:43 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_game *game)
{
	//if (game->map)
	//	free_map(game->map);
	//if (game->mlx)
	//{
	//	if (game->wall)
	//		mlx_destroy_image(game->mlx, game->wall);
	//	if (game->floor)
	//		mlx_destroy_image(game->mlx, game->floor);
	//	if (game->player)
	//		mlx_destroy_image(game->mlx, game->player);
	//	if (game->exit)
	//		mlx_destroy_image(game->mlx, game->exit);
	//	if (game->collectible)
	//		mlx_destroy_image(game->mlx, game->collectible);
	//	if (game->window)
	//		mlx_destroy_window(game->mlx, game->window);
	
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

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	read_map(argv[1]);
	return (0);
}