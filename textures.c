/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 08:18:43 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/25 10:00:04 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_one_texture(t_game *game, t_image *image, char *path)
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
