/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:15:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/28 13:13:37 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	exit_game(t_game *game)
{
	if (!game)
		exit(0);
	if (game->texture.ceiling)
		free(game->texture.ceiling);
	if (game->texture.floor)
		free(game->texture.floor);
	if (game->texture.north)
		free(game->texture.north);
	if (game->texture.south)
		free(game->texture.south);
	if (game->texture.east)
		free(game->texture.east);
	if (game->texture.east)
		free(game->texture.west);
	if (game->map.grid)	
		free_tab(game->map.grid);
	if (game->mlx)
	{
		if (game->wall_texture.img)
			mlx_destroy_image(game->mlx, game->wall_texture.img);
		if (game->wall_north.img)
			mlx_destroy_image(game->mlx, game->wall_north.img);
		if (game->image.img)
			mlx_destroy_image(game->mlx, game->image.img);
		if (game->wall_south.img)
			mlx_destroy_image(game->mlx, game->wall_south.img);
		if (game->wall_east.img)
			mlx_destroy_image(game->mlx, game->wall_east.img);
		if (game->wall_west.img)	
			mlx_destroy_image(game->mlx, game->wall_west.img);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

void	print_error_exit(t_game *game, char *end_mes)
{
	if (end_mes)
		printf("%s", end_mes);
	exit_game(game);
}
