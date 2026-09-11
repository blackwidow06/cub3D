/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:02:06 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/11 11:41:14 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

typedef struct s_game
{
	void	*mlx;
	void	*window;

	//void	*wall;
	//void	*floor;
	//void	*player;
	//void	*exit;

	//char	**map;
	//int		map_width;
	//int		map_height;

	//int		player_x;
	//int		player_y;
	//int		moves;
}	t_game;

#endif