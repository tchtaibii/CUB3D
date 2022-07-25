/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:19:18 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/05 16:26:27 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	unsigned char	*x;
	unsigned char	*x2;
	int				i;

	x = (unsigned char *)s1;
	x2 = (unsigned char *)s2;
	if (!x || !x2)
		return (0);
	i = 0;
	if (n == 0)
		return (0);
	while (x[i] != '\0' && x2[i] != '\0' && x[i] == x2[i] && i < n - 1)
	{
		i++;
	}
	return (x[i] - x2[i]);
}
