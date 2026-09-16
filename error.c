/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:15:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/16 11:05:01 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	exit(0);
}
