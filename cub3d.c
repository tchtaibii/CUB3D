/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:11:35 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/26 20:23:15 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(void)
{
	exit(0);
	return (0);
}

void	ft_init(t_img *img)
{
	if (img->map[img->i][img->j] == 'N' || img->map[img->i][img->j] == 'S' || \
		img->map[img->i][img->j] == 'W' || img->map[img->i][img->j] == 'E')
	{
		if (img->map[img->i][img->j] == 'N')
			img->r = 270;
		else if (img->map[img->i][img->j] == 'S')
			img->r = 90;
		else if (img->map[img->i][img->j] == 'W')
			img->r = 180;
		else if (img->map[img->i][img->j] == 'E')
			img->r = 0;
		img->x0 = img->j * SIZE_IMG;
		img->y0 = img->i * SIZE_IMG;
	}
}

void	ft_drawmap(t_cub *cub)
{
	t_img	img;

	img.i = -1;
	img.map = cub->map;
	img.mlx = mlx_init();
	ft_sheftcolor(&img, cub);
	img.mlx_win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	img.data.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.data.addr = mlx_get_data_addr(img.data.img, &img.data.bits_per_pixel, \
		&img.data.line_length, &img.data.endian);
	img = ft_img(img, cub);
	while (img.map[++img.i])
	{
		img.j = -1;
		while (img.map[img.i][++img.j])
			ft_init(&img);
	}
	ft_rays(&img);
	ft_hooks(img);
}

char	**ft_split_file(char *str)
{
	char	**map;
	char	*s;
	char	*st;
	int		i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			st = ft_substr(str, 0, i + 1);
			s = ft_substr(str, i + 1, ft_strlen(str) - i);
			str = ft_strjoin(st, " ");
			str = ft_strjoin(str, s);
		}
		i++;
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

int	main(int ac, char **av)
{
	t_cub	*cub;
	char	**map;
	char	*str;

	if (ac != 2)
		return (ft_return(("Error: Bad Arg")));
	else
	{
		ft_checkex(av[1]);
		str = ft_getmap(av[1]);
		if (!last_char(str))
			return (ft_return("ERROR"));
		map = ft_split_file(str);
		if (!map[0])
			return (ft_return("Error: empty file!"));
		ft_checkfile(map);
		cub = ft_parse(map);
		if (!ft_checktexture(cub))
			return (ft_return("check texture"));
		ft_checkcomma(cub);
		if (!ft_initcolor(cub))
			return (ft_return("check color"));
		ft_checkmap(cub->map);
		ft_drawmap(cub);
	}
}
