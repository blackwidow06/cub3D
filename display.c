/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:49:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/11 11:04:15 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, 800, 600, "Cub3D");
	if (!window)
		return (1);
	mlx_loop(mlx);
	return (0);
}
