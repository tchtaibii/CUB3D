/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:14:03 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/07/26 19:47:45 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_0(t_img *img)
{
	img->y = round((img->y0 - (sin(((img->r + 90) % 360) \
	* M_PI / 180) * 10) * 2) / SIZE_IMG);
	img->x = round((img->x0 - (cos(((img->r + 90) % 360) \
	* M_PI / 180) * 10) * 2) / SIZE_IMG);
	if (img->map[(int)img->y][(int)img->x] == '1' \
	|| img->map[(int)img->y][(int)img->x] == '\0')
		return ;
	else
	{
		img->x0 -= (cos(((img->r + 90) % 360) * M_PI / 180) * 10);
		img->y0 -= (sin(((img->r + 90) % 360) * M_PI / 180) * 10);
	}
}

void	ft_key_1(t_img *img)
{
	img->y = round((img->y0 - (sin(img->r * M_PI / 180) * 10) * 2) / SIZE_IMG);
	img->x = round((img->x0 - (cos(img->r * M_PI / 180) * 10) * 2) / SIZE_IMG);
	if (img->map[(int)img->y][(int)img->x] == '1' \
	|| img->map[(int)img->y][(int)img->x] == '\0')
		return ;
	else
	{
		img->x0 -= cos(img->r * M_PI / 180) * 10;
		img->y0 -= sin(img->r * M_PI / 180) * 10;
	}
}

void	ft_key_2(t_img *img)
{
	img->y = round((img->y0 + (sin((img->r + 90) \
	* M_PI / 180) * 10) * 2) / SIZE_IMG);
	img->x = round((img->x0 + (cos((img->r + 90) \
	* M_PI / 180) * 10) * 2) / SIZE_IMG);
	if (img->map[(int)img->y][(int)img->x] == '1' \
	|| img->map[(int)img->y][(int)img->x] == '\0')
		return ;
	else
	{
		img->x0 = (img->x0 + (cos(((img->r + 90) % 360) \
		* M_PI / 180) * 10));
		img->y0 = (img->y0 + (sin(((img->r + 90) % 360) \
		* M_PI / 180) * 10));
	}
}

void	ft_key_13(t_img *img)
{
	img->y = round((img->y0 + (sin(img->r * M_PI / 180) * 10) * 2) / SIZE_IMG);
	img->x = round((img->x0 + (cos(img->r * M_PI / 180) * 10) * 2) / SIZE_IMG);
	if (img->map[(int)img->y][(int)img->x] == '1' \
	|| img->map[(int)img->y][(int)img->x] == '\0')
		return ;
	else
	{
		img->y0 += sin(img->r * M_PI / 180) * 10;
		img->x0 += cos(img->r * M_PI / 180) * 10;
	}
}
