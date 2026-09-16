/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:02:06 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/15 13:00:08 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*ceiling;
	char		*floor;

}				t_texture;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;

}				t_map;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;

}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;

	t_map		map;
	t_texture	texture;

}				t_game;

/*parsing/check_texture.c*/
int		check_map_file(char *filename);
int		check_textures(t_texture *texture);

/*pasing/read_map.c*/
int		read_map(char *filename, t_texture *texture);

/*parsing/parsing.c*/
int		parsing(char *filename, t_game *game);

/*parsing/check_colors.c*/
int		check_colors(char **color, char *line);
int		check_all_colors(t_texture *texture);
int		check_rgb(char *color);

/*parsing/read_map_grid.c*/
int		read_map_grid(char *filename, t_map *map);

/*parsing/check_map_utils.c*/
int		check_map_characters(t_map *map);
int		check_player_count(t_map *map);
int		is_map_line(char *line);

/*parsing/check_map_walls.c*/
int		check_map_walls(t_map *map);

/*parsing/utils.c*/
char	*skip_spaces(char *str);
void	remove_newline(char *line);
int		get_map_width(t_map *map);

/*init_struct.c*/
void	init_texture(t_texture *texture);
void	init_game(t_game *game);
void	init_map(t_map *map);

/*error.c*/
int		exit_game(t_game *game, char *end_mes);

#endif