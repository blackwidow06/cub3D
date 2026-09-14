/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 13:21:33 by mrojouan          #+#    #+#             */
/*   Updated: 2026/09/14 13:22:46 by mrojouan         ###   ########.fr       */
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
            put_pixel(img, x, y, 0x00334455);
            x++;
        }
        y++;
    }
}
