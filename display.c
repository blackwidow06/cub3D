/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:49:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/11 11:27:46 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_window(t_game *game)
{
	if (game->map)
		free_tab(game->map);
	if (game->mlx)
	{
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		if (game->collect)
			mlx_destroy_image(game->mlx, game->collect);
		if (game->exit)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		gnl_clear(game);
		free(game->mlx);
	}
	exit(1);
}

int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, 800, 600, "Cub3D");
	if (!window)
		return (1);
	mlx_loop(mlx);
	return (0);
}
