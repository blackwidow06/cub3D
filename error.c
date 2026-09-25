/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:15:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/25 13:08:56 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	exit_game(t_game *game)
{
	free(game->texture.ceiling);
	free(game->texture.floor);
	free(game->texture.north);
	free(game->texture.south);
	free(game->texture.east);
	free(game->texture.west);
	if (game->mlx)
	{
		if (game->image.img)
			mlx_destroy_image(game->mlx, game->image.img);
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
