/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:30:50 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/14 13:35:16 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void put_pixel(t_image *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length
            + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void draw_background(t_image *img)
{
    int x;
    int y;

    y = 0;
    while (y < 720)
    {
        x = 0;
        while (x < 1280)
        {
            put_pixel(img, x, y, 0x00FF00);
            x++;
        }
        y++;
    }
}

int    key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game, "Exit game\n");
    return (0);
}

int	open_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->window = mlx_new_window(game->mlx, 1280, 720, "Cub3D");
	if (!game->window)
		return (1);
	game->image.img = mlx_new_image(game->mlx, 1280, 720);
	game->image.addr = mlx_get_data_addr(
    game->image.img,
    &game->image.bits_per_pixel,
    &game->image.line_length,
    &game->image.endian);
	draw_background(&game->image);
	mlx_put_image_to_window(
    game->mlx,
    game->window,
    game->image.img,
    0,
    0
);
	mlx_hook(game->window, 17, 0, exit_game, &game);
	mlx_hook(game->window, 2, 1L << 0, key_press, &game);
	mlx_loop(game->mlx);
	return (0);
}