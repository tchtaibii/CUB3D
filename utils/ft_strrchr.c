/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:24:25 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/05 16:26:34 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strrchr(char *s, int c)
{
	char	*str;
	int		i;

	str = (char *) s;
	c = (char)c;
	i = ft_strlen(s);
	if (c == 0)
		return (str + ft_strlen(str));
	while (i >= 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	return (0);
}
