/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:43:16 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/25 17:32:49 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_wall(t_img *img, t_ddi *ddi)
{
	if (img->map[(int)(ddi->y / 40)][(int)((ddi->x - ddi->xinc) / 40)] != '1')
	{
		if (ddi->xinc > 0)
			ddi->dwall = 1;
		else
			ddi->dwall = 2;
	}
	else if (img->map[(int)((ddi->y - ddi->yinc) / 40)] \
	[(int)(ddi->x / 40)] != '1')
	{
		if (ddi->yinc > 0)
			ddi->dwall = 3;
		else
			ddi->dwall = 4;
	}
}

int	ft_getcolor(t_ddi *ddi, t_img *img, int y, int x)
{
	char	*dst;

	x %= 40;
	y %= 40;
	if (ddi->dwall == 1)
	{
		dst = img->pics[0].addr + (y * img->pics[0].line_length + x * \
		(img->pics[0].bits_per_pixel / 8));
		return (*(int *)dst);
	}
	else if (ddi->dwall == 2)
	{
		dst = img->pics[1].addr + (y * img->pics[1].line_length + x * \
		(img->pics[1].bits_per_pixel / 8));
		return (*(int *)dst);
	}
	else if (ddi->dwall == 3)
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

void	ft_draw(t_img *img, t_ddi *ddi)
{
	int		dakshi;
	float	d;
	float	ca;
	int		j;

	ft_wall(img, ddi);
	d = sqrt(pow((ddi->y - ddi->y0), 2) + pow((ddi->x - ddi->x0), 2));
	ca = ((img->r * M_PI) / 180) - (((img->r + img->a) * M_PI) / 180);
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	d = d * cos(ca);
	dakshi = (40 * WIN_HEIGHT) / d;
	j = -1;
	while (++j < WIN_HEIGHT && img->y < WIN_WIDTH)
	{
		if (j < (int)(WIN_HEIGHT - dakshi) / 2)
			my_mlx_pixel_put(&img->data, img->y, j, img->ceilling);
		else if (j <= (int)((WIN_HEIGHT - dakshi) / 2) + dakshi)
		{
			if (ddi->dwall == 1 || ddi->dwall == 2)
				ddi->c = fmod(ddi->y / 40, 1);
			else
				ddi->c = fmod(ddi->x / 40, 1);
			ddi->c *= 40;
			my_mlx_pixel_put(&img->data, img->y, j, ft_getcolor(ddi, img, (int)(((j - (int)((WIN_HEIGHT - dakshi) / 2)) * 40) / dakshi), (int)ddi->c));
		}
		else
			my_mlx_pixel_put(&img->data, img->y, j, img->floor);
	}
}

void	ft_dda(t_img *img, t_ddi *ddi)
{
	ddi->dx = ddi->x1 - ddi->x0;
	ddi->dy = ddi->y1 - ddi->y0;
	if (abs(ddi->dx) > abs(ddi->dy))
		ddi->steps = abs(ddi->dx);
	else
		ddi->steps = abs(ddi->dy);
	ddi->xinc = ddi->dx / (float) ddi->steps;
	ddi->yinc = ddi->dy / (float) ddi->steps;
	ddi->x = ddi->x0;
	ddi->y = ddi->y0;
	while (1)
	{
		if (img->map[(int)(ddi->y / 40)][(int)(ddi->x / 40)] == '1' \
			|| img->map[(int)(ddi->y / 40)][(int)(ddi->x / 40)] == ' ' \
			|| !img->map[(int)(ddi->y / 40)][(int)(ddi->x / 40)])
			break ;
		ddi->x += ddi->xinc;
		ddi->y += ddi->yinc;
	}
	ft_draw(img, ddi);
}
