/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:55:13 by iel-mach          #+#    #+#             */
/*   Updated: 2022/06/23 23:55:35 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_before_line(char *s)
{
	int	i;

	if (!s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (ft_substr(s, 0, i + 1));
}

char	*ft_after_line(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			str = ft_substr(s, i + 1, ft_strlen(s));
			free (s);
			return (str);
		}
		i++;
	}
	free (s);
	return (NULL);
}

char	*ft_getline(int fd, char *a)
{
	char	*str;
	int		t;

	str = malloc (2);
	t = 1;
	while (!check_line(a) && t)
	{
		t = read(fd, str, 1);
		if (t == -1)
		{
			free(str);
			return (NULL);
		}
		str[t] = '\0';
		a = ft_strjoin(a, str);
	}
	free(str);
	return (a);
}

char	*get_next_line(int fd)
{
	static char	*red;
	char		*l;

	if (fd < 0)
		return (NULL);
	red = ft_getline(fd, red);
	if (!red)
		return (NULL);
	l = ft_before_line (red);
	red = ft_after_line(red);
	return (l);
}
