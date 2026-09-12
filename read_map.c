/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 09:08:11 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/12 10:10:55 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NO ./textures/north.xpm    /*chemin des textures*/
//SO ./textures/south.xpm
//WE ./textures/west.xpm
//EA ./textures/east.xpm  

//F 220,100,0   == couleur sol
//C 135,206,235 == couleur plafond

//111111
//100001
//1000N1
//111111

/*parsing doit lire le fihier map ligne par ligne, recupere le chemin de 
la texture et le stocke dans la structure (north_texture) ensuite on peut
charger l'image (comme dans so_long un peu)*/

#include "cub3D.h"

int	read_map(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line!= NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}