/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkutils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:48:10 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/07/26 19:58:07 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_norm(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_sir(t_cub *cub, char **map, int i)
{
	int	j;
	int	a;

	j = 0;
	while (map[j])
		j++;
	a = j - i;
	cub->map = malloc(sizeof(char *) * (a + 1));
	j = 0;
	while (map[i])
		cub->map[j++] = ft_strdup(map[i++]);
	cub->map[j] = NULL;
	ft_free_norm(map);
}

int	ft_checkzero(int i, char *str, char *str1)
{
	int	a;
	int	b;

	a = ft_strlen(str);
	b = ft_strlen(str1);
	i++;
	if (i > a || i > b)
		return (0);
	return (1);
}

int	ft_parser_2(char *map, t_cub *cub)
{
	if (!ft_strncmp(map, "NO ", 3))
		cub->n = ft_skip(map);
	else if (!ft_strncmp(map, "SO ", 3))
		cub->s = ft_skip(map);
	else if (!ft_strncmp(map, "WE ", 3))
		cub->w = ft_skip(map);
	else if (!ft_strncmp(map, "EA ", 3))
		cub->e = ft_skip(map);
	else if (!ft_strncmp(map, "F ", 2))
		cub->f = ft_skip(map);
	else if (!ft_strncmp(map, "C ", 2))
		cub->c = ft_skip(map);
	else if (!ft_strncmp(map, "1", 1))
		return (0);
	return (1);
}

t_cub	*ft_parse(char **map)
{
	t_cub	*cub;
	int		i;
	int		j;

	i = -1;
	cub = malloc (sizeof(t_cub));
	if (!cub)
		return (NULL);
	while (map[++i])
	{
		j = 0;
		if (map[i][j] == ' ')
		{
			while (map[i][j] == ' ')
				j++;
			if (map[i][j] == '\0')
				i++;
			else
				break ;
		}
		if (!ft_parser_2(map[i], cub))
			break ;
	}
	ft_sir(cub, map, i);
	return (cub);
}
