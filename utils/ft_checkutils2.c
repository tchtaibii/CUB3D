/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkutils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:53:54 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/26 02:11:00 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_checkex(char *str)
{
	char	*ex;

	if (!str)
		exit(1);
	ex = ft_strrchr(str, '.');
	if (!ex)
	{
		printf("map extension invalide !\n");
		exit(1);
	}
	if (ft_strncmp(ex, ".cub", 4) || ft_strlen(ex) != 4)
	{
		printf("map extension must be end with .cub !\n");
		exit(1);
	}
}

char	*ft_getmap(char *str)
{
	char	*get;
	char	*join;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: cannot open map\n");
		exit(1);
	}
	get = get_next_line(fd);
	join = ft_strdup("");
	while (get)
	{
		join = ft_strjoin(join, get);
		free(get);
		get = get_next_line(fd);
	}
	return (join);
}

int	ft_checkspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '*')
		i++;
	if (str[i] == '1')
		return (1);
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	ft_checkfile(char **map)
{
	t_check	check;

	check = ft_check_init();
	while (map[++check.i])
	{
		if (!ft_strncmp(map[check.i], "NO ", 3))
			check.n++;
		else if (!ft_strncmp(map[check.i], "SO ", 3))
			check.s++;
		else if (!ft_strncmp(map[check.i], "WE ", 3))
			check.w++;
		else if (!ft_strncmp(map[check.i], "EA ", 3))
			check.e++;
		else if (!ft_strncmp(map[check.i], "F ", 2))
			check.f++;
		else if (!ft_strncmp(map[check.i], "C ", 2))
			check.c++;
		else if (ft_checkspace(map[check.i]))
			;
		else
			ft_exit_f();
	}
	ft_errors(check);
}

int	ft_skipspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	return (0);
}
