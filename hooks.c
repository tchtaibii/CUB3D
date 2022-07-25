/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:39:27 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/25 15:32:36 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hooks(t_img img)
{
	mlx_hook(img.mlx_win, 02, 1L << 0, ft_keyhook, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.data.img, 0, 0);
	mlx_hook(img.mlx_win, 17, 0, ft_exit, NULL);
	mlx_loop(img.mlx);
}

void	ft_rays(t_img *img)
{
	t_ddi	ddi;

	img->y = -1;
	img->a = -32;
	while (++img->y < WIN_WIDTH)
	{
		ddi.x0 = img->x0 + 20;
		ddi.y0 = img->y0 + 20;
		ddi.x1 = img->x0 + (1000 * cos((img->r + img->a) * M_PI / 180));
		ddi.y1 = img->y0 + (1000 * sin((img->r + img->a) * M_PI / 180));
		ft_dda(img, &ddi);
		if (img->a < 64)
			img->a += (float)1 / (WIN_WIDTH / 64);
	}
}

int	ft_keyhook(int key, t_img *img)
{
	if (key == 13)
	{
		img->y = round((img->y0 + (sin(img->r * M_PI / 180) * 10) * 2) / 40);
		img->x = round((img->x0 + (cos(img->r * M_PI / 180) * 10) * 2) / 40);
		if (img->map[(int)img->y][(int)img->x] == '1')
			return (0);
		else
		{
			img->y0 += sin(img->r * M_PI / 180) * 10;
			img->x0 += cos(img->r * M_PI / 180) * 10;
		}
	}
	else if (key == 0)
	{
		img->y = round((img->y0 - (sin(((img->r + 90) % 360) * M_PI / 180) * 10) * 2) / 40);
		img->x = round((img->x0 - (cos(((img->r + 90) % 360) * M_PI / 180) * 10) * 2) / 40);
		if (img->map[(int)img->y][(int)img->x] == '1')
			return (0);
		else
		{
			img->x0 -= (cos(((img->r + 90) % 360) * M_PI / 180) * 10);
			img->y0 -= (sin(((img->r + 90) % 360) * M_PI / 180) * 10);
		}
	}
	else if (key == 1)
	{
		img->y = round((img->y0 - (sin(img->r * M_PI / 180) * 10) * 2) / 40);
		img->x = round((img->x0 - (cos(img->r * M_PI / 180) * 10) * 2) / 40);
		if (img->map[(int)img->y][(int)img->x] == '1')
			return (0);
		else
		{
			img->x0 -= cos(img->r * M_PI / 180) * 10;
			img->y0 -= sin(img->r * M_PI / 180) * 10;
		}
	}
	else if (key == 2)
	{

		img->y = round((img->y0 + (sin((img->r + 90) * M_PI / 180) * 10) * 2) / 40);
		img->x = round((img->x0 + (cos((img->r + 90) * M_PI / 180) * 10) * 2) / 40);
		if (img->map[(int)img->y][(int)img->x] == '1')
			return (0);
		else
		{
			img->x0 = (img->x0 + (cos(((img->r + 90) % 360) * M_PI / 180) * 10));
			img->y0 = (img->y0 + (sin(((img->r + 90) % 360) * M_PI / 180) * 10));
		}
	}
	else if (key == 124)
		img->r += 5;
	else if (key == 123)
		img->r -= 5;
	else if (key == 53)
		ft_exit();
	if (img->r > 360)
		img->r = 0;
	if (img->r < 0)
		img->r = 360;
	ft_rays(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->data.img, 0, 0);
	return (0);
}
