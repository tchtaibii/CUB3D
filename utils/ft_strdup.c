/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:01:10 by iel-mach          #+#    #+#             */
/*   Updated: 2022/06/24 07:02:45 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		len;
	int		i;
	int		x;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	ptr = malloc (len + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	x = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	s1 = ptr;
	return (s1);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		a;
	int		b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	new = malloc ((a + b + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < a)
		new[i++] = s1[j++];
	j = 0;
	while (j < b)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
