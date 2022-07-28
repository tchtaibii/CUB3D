/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:43:16 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/28 19:44:13 by iel-mach         ###   ########.fr       */
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
	if (img->map[(int)(ddi->y / SIZE_IMG)][(int)((ddi->x \
	- ddi->xinc) / SIZE_IMG)] != '1')
	{
		if (ddi->xinc > 0)
			ddi->dwall = 1;
		else
			ddi->dwall = 2;
	}
	else if (img->map[(int)((ddi->y - ddi->yinc) / SIZE_IMG)] \
	[(int)(ddi->x / SIZE_IMG)] != '1')
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

	x %= SIZE_IMG;
	y %= SIZE_IMG;
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
	else
		return (ft_getcolor_norm(ddi, img, y, x));
	return (0);
}

void	ft_draw(t_img *img, t_ddi *ddi)
{
	int		dakshi;
	float	d;
	float	ca;

	ft_wall(img, ddi);
	d = sqrt(pow((ddi->y - ddi->y0), 2) + pow((ddi->x - ddi->x0), 2));
	ca = ((img->r * M_PI) / 180) - (((img->r + img->a) * M_PI) / 180);
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	d = d * cos(ca);
	dakshi = (SIZE_IMG * WIN_HEIGHT) / d;
	ft_draw_norm(img, ddi, dakshi);
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
		if (img->map[(int)(ddi->y / SIZE_IMG)][(int)(ddi->x / SIZE_IMG)] == '1' \
			|| img->map[(int)(ddi->y / SIZE_IMG)][(int)(ddi->x \
			/ SIZE_IMG)] == ' ' \
			|| !img->map[(int)(ddi->y / SIZE_IMG)][(int)(ddi->x / SIZE_IMG)])
			break ;
		ddi->x += ddi->xinc;
		ddi->y += ddi->yinc;
	}
	ft_draw(img, ddi);
}
