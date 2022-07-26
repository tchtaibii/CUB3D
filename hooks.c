/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:39:27 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/26 02:20:11 by tchtaibi         ###   ########.fr       */
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
		ft_key_13(img);
	else if (key == 0)
		ft_key_0(img);
	else if (key == 1)
		ft_key_1(img);
	else if (key == 2)
		ft_key_2(img);
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
