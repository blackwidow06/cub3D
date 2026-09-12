/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 13:09:43 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/12 13:22:12 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	exit_game(t_game *game, char *end_mes)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (end_mes)
		printf("%s", end_mes);
	exit(0);
}