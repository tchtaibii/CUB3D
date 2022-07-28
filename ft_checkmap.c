/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:14:14 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/28 19:52:03 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_checkmap2(char **map, int i, int j)
{
	if (i == 0)
	{
		if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\t')
		{
			printf("Error: check map!\n");
			exit(1);
		}
	}
	if (map[i + 1] != NULL)
	{
		if ((map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S' \
			|| map[i][j] == 'E') && (map[i][j - 1] \
			== ' ' || map[i][j + 1] == ' '
			|| map[i - 1][j] == ' ' || map[i + 1][j] == ' '))
		{
			printf("Error: check map!\n");
			exit(1);
		}
	}
	if ((map[i][j] != '1' && map[i][j] != ' ') && map[i][j + 1] == '\0')
	{
		printf("Error: check map!\n");
		exit(1);
	}
}

void	ft_checkmap3(char **map, int i, int j)
{
	if (map[i + 1] == NULL && map[i][j] != '1' && map[i][j] != ' ' \
		&& map[i][j] != '\t')
	{
		printf("Error: check map!\n");
		exit(1);
	}
	if (i != 0 && map[i][j] == '0' && map[i + 1] != NULL)
	{
		if (!ft_checkzero(j, map[i - 1], map[i + 1]))
		{
			printf("Error: check map!\n");
			exit(1);
		}
	}
	if (i != 0 && j != 0 && map[i + 1] != NULL && map[i][j + 1] != '\0' \
		&& map[i][j] == '0')
	{
		if (map[i][j] == '0' && (map[i][j - 1] == ' ' || map[i][j + 1] == ' '
			|| map[i - 1][j] == ' ' || map[i + 1][j] == ' '))
		{
			printf("Error: check map!\n");
			exit(1);
		}
	}
}

void	ft_checkmap4(t_check *t, char **map, int i, int j)
{
	if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' \
		&& map[i][j] != '\t' \
		&& map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'S' \
		&& map[i][j] != 'E')
	{
		printf("Error: check map!\n");
		exit(1);
	}
	if (map[i][j] == 'N' || map[i][j] == 'S' \
		|| map[i][j] == 'W' || map[i][j] == 'E')
		t->g++;
	if (map[i][j] == 'N')
		t->no++;
	if (map[i][j] == 'S')
		t->so++;
	if (map[i][j] == 'W')
		t->we++;
	if (map[i][j] == 'E')
		t->ea++;
}

void	ft_checkmap(char **map)
{
	t_check	t;
	int		i;
	int		j;

	i = -1;
	t.no = 0;
	t.so = 0;
	t.we = 0;
	t.ea = 0;
	t.g = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][0] == ' ' && map[i][1] == '\0')
				ft_exit_f();
			ft_checkmap2(map, i, j);
			ft_checkmap3(map, i, j);
			ft_checkmap4(&t, map, i, j);
		}
	}
	if (t.no > 1 || t.ea > 1 || t.we > 1 || t.so > 1 || t.g > 1 || t.g == 0)
		ft_check_norm();
}
