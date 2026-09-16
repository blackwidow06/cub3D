/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 14:27:36 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/16 15:37:41 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	player_plane(t_player *player, char curr)
{
	if (curr == 'N')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (curr == 'S')
	{
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (curr == 'E')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (curr == 'W')
	{
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

static void	player_direction(t_player *player, char curr)
{
	if (curr == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (curr == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (curr == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (curr == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

int	parse_player(t_game *game)
{
	char	curr;
	int		i;
	int		j;

	i = 0;
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			curr = game->map.grid[i][j];
			if (curr == 'N' || curr == 'S' || curr == 'E' || curr == 'W')
			{
				game->player.x = j + 1;
				game->player.y = i + 1;
				player_direction(&game->player, curr);
				player_plane(&game->player, curr);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
