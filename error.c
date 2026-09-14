/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:15:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/14 10:38:02 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_game *game, char *end_mes)
{
	if (game->mlx)
	{	
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (end_mes)
		printf("%s", end_mes);
	exit(0);
}
