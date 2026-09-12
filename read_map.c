/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 09:08:11 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/12 13:04:57 by malavaud         ###   ########.fr       */
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

int	check_map_file(char *filename)
{
	int len;
	int	fd;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	return (0);
}

static	int	check_texture_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_textures(t_texture *texture)
{
	if (texture->north == NULL)
		return (1);
	if (texture->south == NULL)
		return (1);
	if (texture->west == NULL)
		return (1);
	if (texture->east == NULL)
		return (1);
	if (check_texture_file(texture->north) != 0)
		return (1);
	if (check_map_file(texture->south) != 0)
		return (1);
	if (check_texture_file(texture->west) != 0)
		return (1);
	if (check_texture_file(texture->east) != 0)
		return (1);
	return (0);
}

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

