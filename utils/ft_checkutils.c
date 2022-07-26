/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:49:40 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/26 02:47:48 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_initcolor(t_cub *cub)
{
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
	while (c[i])
	{
		if (c[i] == ',')
			comma++;
		i++;
	}
	i = 0;
	while (f[i])
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
