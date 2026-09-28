/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 08:18:43 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/25 13:20:28 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int	load_one_texture(t_game *game, t_image *image, char *path)
{
	image->img = mlx_xpm_file_to_image(
			game->mlx,
			path,
			&image->width,
			&image->height);
	if (!image->img)
		return (1);
	image->addr = mlx_get_data_addr(
			image->img,
			&image->bits_per_pixel,
			&image->line_length,
			&image->byte_order);
	return (0);
}

int	load_wall_textures(t_game *game)
{
	if (load_one_texture(game, &game->wall_north,
			game->texture.north))
		return (1);
	if (load_one_texture(game, &game->wall_south,
			game->texture.south))
		return (1);
	if (load_one_texture(game, &game->wall_east,
			game->texture.east))
		return (1);
	if (load_one_texture(game, &game->wall_west,
			game->texture.west))
		return (1);
	return (0);
}

int	get_texture_pixel(t_image *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

int	get_texture_x(t_game *game)
{
	t_image	*texture;
	double	wall_x;
	int		texture_x;

	texture = get_wall_texture(game);
	if (game->ray.side == 0)
		wall_x = game->player.y
			+ game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		wall_x = game->player.x
			+ game->ray.perp_wall_dist * game->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * texture->width);
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
		texture_x = texture->width - texture_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir_y < 0)
		texture_x = texture->width - texture_x - 1;
	return (texture_x);
}

t_image	*get_wall_texture(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x > 0)
			return (&game->wall_west);
		return (&game->wall_east);
	}
	if (game->ray.ray_dir_y > 0)
		return (&game->wall_north);
	return (&game->wall_south);
}
