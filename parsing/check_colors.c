/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:28:16 by malavaud          #+#    #+#             */
/*   Updated: 2026/09/15 11:14:41 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse_colors(t_texture *texture, char *line)
{
	if (line[0] == 'F'
		&& (line[1] == ' ' || line[1] == '\t'))
		return (check_colors(&texture->floor, line));
	else if (line[0] == 'C'
		&& (line[1] == ' ' || line[1] == '\t'))
		return (check_colors(&texture->ceiling, line));
	return (0);
}

int	check_colors(char **color, char *line)
{
	if (*color != NULL)
		return (1);
	line++;
	line = skip_spaces(line);
	if (*line == '\0')
		return (1);
	*color = ft_strdup(line);
	if (*color == NULL)
		return (1);
	return (0);
}

int	check_all_colors(t_texture *texture)
{
	if (texture->floor == NULL)
		return (1);
	else if (texture->ceiling == NULL)
		return (1);
	else if (check_rgb(texture->floor) != 0)
		return (1);
	else if (check_rgb(texture->ceiling) != 0)
		return (1);
	return (0);
}

static	int	check_value_colors(char *str)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (value > 255)
		return (1);
	return (0);
}

int	check_rgb(char *color)
{
	char	**rgb;
	int		i;
	int		error;

	rgb = ft_split(color, ',');
	if (rgb == NULL)
		return (1);
	i = 0;
	error = 0;
	while (rgb[i])
	{
		if (check_value_colors(rgb[i]) != 0)
			error = 1;
		i++;
	}
	if (i != 3)
		error = 1;
	free_split(rgb, 3);
	return (error);
}
