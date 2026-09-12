/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 09:08:11 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/12 14:00:25 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*parsing doit lire le fihier map ligne par ligne, recupere le chemin de 
la texture et le stocke dans la structure (north_texture) ensuite on peut
charger l'image (comme dans so_long un peu)*/

/*Lire le fichier .cub
arreter la lecture du fichier si ya pas
Récupérer les textures et les couleurs
Vérifier qu’il ne manque rien
Vérifier que les chemins sont valides
Lire et vérifier la map
Initialiser la fenêtre et le raycasting*/

#include "cub3D.h"

int	read_map(char *filename, t_texture *texture)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line!= NULL)
	{
		if (ft_strncmp(line, "NO ", 3) == 0) /*si NO*/
			texture->north = ft_strdup(line + 3); /* recupere le chemi et stocke dans texture->north*/
		else if (ft_strncmp(line, "SO ", 3) == 0)
			texture->south = ft_strdup(line + 3);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			texture->west = ft_strdup(line + 3);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			texture->east = ft_strdup(line + 3);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}

