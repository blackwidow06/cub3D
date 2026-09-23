/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:15:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/22 12:47:07 by mrojouan         ###   ########.fr       */
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
}

int	exit_game(t_game *game, char *end_mes)
{
	if (game->mlx)
	{
		if (game->image.img)
			mlx_destroy_image(game->mlx, game->image.img);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (end_mes)
		printf("%s", end_mes);
	free_tab(&game->texture.ceiling);
	free_tab(&game->texture.floor);
	exit(0);
}
