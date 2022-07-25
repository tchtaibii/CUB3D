/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:03:25 by iel-mach          #+#    #+#             */
/*   Updated: 2022/06/24 00:05:43 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_c(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	count_w(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] != c) || (str[i] != c && str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**split(char **arr, char *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = count_c(s + i, c);
		if (s[i] && s[i] != c)
		{
			arr[len] = ft_substr(s, i, j);
			i += j;
			len++;
		}
	}
	arr[len] = 0;
	return (arr);
}

char	**ft_split(char *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = malloc ((count_w(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	split(arr, s, c);
	return (arr);
}
