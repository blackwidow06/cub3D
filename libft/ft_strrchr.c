/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:13:15 by malavaud          #+#    #+#             */
/*   Updated: 2025/10/15 17:51:40 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			cc;
	char			*res;

	i = 0;
	res = NULL;
	cc = (char)c;
	while (str[i])
	{
		if (str[i] == cc)
			res = ((char *) &str[i]);
		i++;
	}
	if (str[i] == cc)
		res = ((char *) &str[i]);
	return (res);
}
