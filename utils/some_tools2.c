/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:39:30 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/07/28 19:41:14 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_getcolor_norm(t_ddi *ddi, t_img *img, int y, int x)
{
	char	*dst;

	if (ddi->dwall == 3)
	{
		dst = img->pics[2].addr + (y * img->pics[2].line_length + x * \
		(img->pics[2].bits_per_pixel / 8));
		return (*(int *)dst);
	}
	else if (ddi->dwall == 4)
	{
		dst = img->pics[3].addr + (y * img->pics[3].line_length + x * \
		(img->pics[3].bits_per_pixel / 8));
		return (*(int *)dst);
	}
	return (0);
}

void	ft_draw_norm(t_img *img, t_ddi *ddi, int dakshi)
{
	int	j;

	j = -1;
	while (++j < WIN_HEIGHT && img->y < WIN_WIDTH)
	{
		if (j < (int)(WIN_HEIGHT - dakshi) / 2)
			my_mlx_pixel_put(&img->data, img->y, j, img->ceilling);
		else if (j <= (int)((WIN_HEIGHT - dakshi) / 2) + dakshi)
		{
			if (ddi->dwall == 1 || ddi->dwall == 2)
				ddi->c = fmod(ddi->y / SIZE_IMG, 1);
			else
				ddi->c = fmod(ddi->x / SIZE_IMG, 1);
			ddi->c *= SIZE_IMG;
			my_mlx_pixel_put(&img->data, img->y, j, ft_getcolor(ddi, img, \
			(int)(((j - (int)((WIN_HEIGHT - dakshi) \
			/ 2)) * SIZE_IMG) / dakshi), \
			(int)ddi->c));
		}
		else
			my_mlx_pixel_put(&img->data, img->y, j, img->floor);
	}
}

void	ft_errors(t_check check)
{
	if (check.n != 1 || check.s != 1 || check.w != 1 \
		|| check.e != 1 || check.f != 1 || check.c != 1)
	{
		printf("Error: check file!\n");
		exit(1);
	}
}

void	ft_exit_f(void)
{
	printf("Error: check file!\n");
	exit(1);
}

t_check	ft_check_init(void)
{
	t_check	check;

	check.n = 0;
	check.s = 0;
	check.w = 0;
	check.e = 0;
	check.f = 0;
	check.c = 0;
	check.i = -1;
	return (check);
}
