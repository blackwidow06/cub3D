/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:02:06 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/18 09:59:24 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <libft.h>
# include <math.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct	s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*ceiling;
	char		*floor;

}			t_texture;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;

}			t_map;

typedef struct s_player
{
	double		x; /*placement*/
	double		y;
	double		dir_x; /*regard du joueur hori*/
	double		dir_y; /*regard du joueur verti*/
	double		plane_x; /*largeur de la camera hori*/
	double		plane_y; /*largeur de la camera verti*/
	double		move_speed;
	double		rot_speed;
}			t_player;

typedef struct	s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_double_y;
	int			map_x;
	int			map_y;
	int			step_X;
	int			step_y;
	double		delta_dist_x; /*distance pour atteindre la next front*/
	double		delta_dist_y;
	double		wall_dist;
	int			side;
	int			line_heigth;
	int			draw_start;
	int			draw_end;
	
}			t_ray;

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	
}			t_image;

typedef struct	s_game
{
	void		*mlx;
	void		*window;

	int			floor_rgb;
	int			ceiling_rgb;

	t_player	player;
	t_texture	texture;
	t_image		image;
	t_map		map;
	t_ray		ray;

}			t_game;

/*parsing/check_texture.c*/
void	remove_newline(char *line);
int		check_map_file(char *filename);
int		check_textures(t_texture *texture);

/*pasing/read_map.c*/
int		read_map(char *filename, t_texture *texture);

/*parsing/parsing.c*/
int		parsing(char *filename, t_game *game);

/*parsing/parse_player.c*/
int		parse_player(t_game *game);

/*parsing/parse.color.c*/
int		parse_color(t_game *game);

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
void	init_player(t_player *player);
void	init_game(t_game *game);
void	init_map(t_map *map);

/*game/game.c*/
int		open_game(t_game *game);

/*game/draw_map.c*/
void	draw_map_2d(t_game *game);
void	draw_player_direction(t_game *game);
void	draw_background(t_game *game);

/*game/movement.c*/
void	move_forward_backward(t_game *game, double direction);
void	move_left_right(t_game *game, double direction);
void	rotate_player(t_game *game, double angle);

/*error.c*/
int		exit_game(t_game *game, char *end_mes);

#endif