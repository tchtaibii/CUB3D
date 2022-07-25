/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:39:30 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/07/25 18:39:52 by tchtaibi         ###   ########.fr       */
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