/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:49:40 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/07 17:07:38 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_initcolor(t_cub *cub)
{
	// t_color	color;
	char	**splt;
	int		i;

	splt = ft_split(cub->f, ',');
	cub->redf = ft_atoi(splt[0]);
	cub->greenf = ft_atoi(splt[1]);
	cub->bluef = ft_atoi(splt[2]);
	if (cub->redf > 255 || cub->greenf > 255 || cub->bluef > 255)
		return (0);
	i = -1;
	while (splt[++i])
		free(splt[i]);
	free(splt);
	splt = ft_split(cub->c, ',');
	cub->redc = ft_atoi(splt[0]);
	cub->greenc = ft_atoi(splt[1]);
	cub->bluec = ft_atoi(splt[2]);
	if (cub->redc > 255 || cub->greenc > 255 || cub->bluec > 255)
		return (0);
	i = -1;
	while (splt[++i])
		free(splt[i]);
	free(splt);
	return (1);
}

int	ft_checkcomma2(char *f, char *c)
{
	int	comma;
	int	i;

	i = 0;
	comma = 0;
	while(c[i])
	{
		if (c[i] == ',')
			comma++;
		i++;
	}
	i = 0;
	while(f[i])
	{
		if (f[i] == ',')
			comma++;
		i++;
	}
	if (comma != 4)
		return (0);
	return (1);
}

int	ft_checkcomma1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ',' && !ft_isdigit(s[i]))
			return (0);
		if (s[0] == ',')
			return (0);
		if (s[i] == ',' && (!ft_isdigit(s[i - 1]) || !ft_isdigit(s[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

void	ft_checkcomma(t_cub *cub)
{
	if (!ft_checkcomma1(cub->c) || !ft_checkcomma1(cub->f))
	{
		printf("check color\n");
		exit (1);
	}
	if (!ft_checkcomma2(cub->c, cub->f))
	{
		printf("check color\n");
		exit (1);
	}
}

int	ft_checktexture(t_cub *cub)
{
	int	fd;

	if (!cub->n || !cub->s || !cub->w || !cub->e || !cub->f || !cub->c)
		return (0);
	fd = open(cub->n, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(cub->s, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(cub->w, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(cub->e, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	ft_checkzero(int i, char *str, char *str1)
{
	int	a;
	int	b;

	a = ft_strlen(str);
	b = ft_strlen(str1);
	if (i > a || i > b)
		return (0);
	return (1);
}

t_cub	*ft_parse(char **map)
{
	t_cub	*cub;
	int		i;
	int		j;
	int		a;

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
		if (!ft_strncmp(map[i], "NO ", 3))
			cub->n = ft_skip(map[i]);
		else if (!ft_strncmp(map[i], "SO ", 3))
			cub->s = ft_skip(map[i]);
		else if (!ft_strncmp(map[i], "WE ", 3))
			cub->w = ft_skip(map[i]);
		else if (!ft_strncmp(map[i], "EA ", 3))
			cub->e = ft_skip(map[i]);
		else if (!ft_strncmp(map[i], "F ", 2))
			cub->f = ft_skip(map[i]);
		else if (!ft_strncmp(map[i], "C ", 2))
			cub->c = ft_skip(map[i]);
		else if (!ft_strncmp(map[i], "1", 1))
			break ;
	}
	j = 0;
	while (map[j])
		j++;
	a = j - i;
	cub->map = malloc(sizeof(char *) * (a + 1));
	j = 0;
	while (map[i])
		cub->map[j++] = ft_strdup(map[i++]);
	cub->map[j] = NULL;
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (cub);
}
