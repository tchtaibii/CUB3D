/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:11:35 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/25 17:04:24 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	ft_img(t_img img)
{
	int k;
	img.pics = malloc(sizeof(t_data) * 4);
	img.pics[0].img = mlx_xpm_file_to_image(img.mlx, "img/1.xpm", &k, &k);
	img.pics[0].addr = mlx_get_data_addr(img.pics[0].img, &img.pics[0].bits_per_pixel, \
					&img.pics[0].line_length, &img.pics[0].endian);
	img.pics[1].img = mlx_xpm_file_to_image(img.mlx, "img/2.xpm", &k, &k);
	img.pics[1].addr = mlx_get_data_addr(img.pics[1].img, &img.pics[1].bits_per_pixel, \
					&img.pics[1].line_length, &img.pics[1].endian);
	img.pics[2].img = mlx_xpm_file_to_image(img.mlx, "img/2.xpm", &k, &k);
	img.pics[2].addr = mlx_get_data_addr(img.pics[2].img, &img.pics[2].bits_per_pixel, \
					&img.pics[2].line_length, &img.pics[2].endian);
	img.pics[3].img = mlx_xpm_file_to_image(img.mlx, "img/1.xpm", &k, &k);
	img.pics[3].addr = mlx_get_data_addr(img.pics[3].img, &img.pics[3].bits_per_pixel, \
					&img.pics[3].line_length, &img.pics[3].endian);
	return (img);
}

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
		img->x0 = img->j * 40;
		img->y0 = img->i * 40;
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
	img = ft_img(img);
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
	{
		printf("Error: Bad Arg\n");
		return (1);
	}
	else
	{
		ft_checkex(av[1]);
		str = ft_getmap(av[1]);
		map = ft_split_file(str);
		if (!map[0])
		{
			printf("Error: empty file!\n");
			return (1);
		}
		ft_checkfile(map);
		cub = ft_parse(map);
		if (!ft_checktexture(cub))
		{
			printf("check texture\n");
			return (1);
		}
		ft_checkcomma(cub);
		if (!ft_initcolor(cub))
		{
			printf("check color\n");
			return (1);
		}
		ft_checkmap(cub->map);
		ft_drawmap(cub);
	}
}
