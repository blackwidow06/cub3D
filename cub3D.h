/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:02:06 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/12 13:16:11 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include <libft.h>
#include <unistd.h>
#include <stdio.h>
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

}			t_game;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*ceiling;
	char	*floor;
	
}			t_texture;

typedef	struct s_map
{
	char	**grid;
	int		width;
	int		height;
	
}			t_map;

typedef	struct s_player
{
	double	x; /*placement*/
	double	y;
	double 	dir_x; /*regard du joueur hori*/
	double	dir_y; /*regard du joueur verti*/
	double	plane_x; /*largeur de la camera hori*/
	double	plane_y; /*largeur de la camera verti*/
	
}			t_player;

/*read_map.c*/
int	read_map(char *filename, t_texture *texture);
int	check_map_file(char *filename);
int	check_textures(t_texture *texture);

#endif