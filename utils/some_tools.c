/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:12:03 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/07/28 19:51:52 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_return(char *str)
{
	printf("%s\n", str);
	return (0);
}

t_img	ft_img(t_img img, t_cub *cub)
{
	int	k;

	img.pics = malloc(sizeof(t_data) * 4);
	img.pics[0].img = mlx_xpm_file_to_image(img.mlx, cub->s, &k, &k);
	img.pics[0].addr = mlx_get_data_addr(img.pics[0].img, \
	&img.pics[0].bits_per_pixel, \
	&img.pics[0].line_length, &img.pics[0].endian);
	img.pics[1].img = mlx_xpm_file_to_image(img.mlx, cub->w, &k, &k);
	img.pics[1].addr = mlx_get_data_addr(img.pics[1].img, \
	&img.pics[1].bits_per_pixel, &img.pics[1].line_length, &img.pics[1].endian);
	img.pics[2].img = mlx_xpm_file_to_image(img.mlx, cub->e, &k, &k);
	img.pics[2].addr = mlx_get_data_addr(img.pics[2].img, \
	&img.pics[2].bits_per_pixel, \
	&img.pics[2].line_length, &img.pics[2].endian);
	img.pics[3].img = mlx_xpm_file_to_image(img.mlx, cub->n, &k, &k);
	img.pics[3].addr = mlx_get_data_addr(img.pics[3].img, \
	&img.pics[3].bits_per_pixel, \
	&img.pics[3].line_length, &img.pics[3].endian);
	return (img);
}

void	ft_sheftcolor(t_img *img, t_cub *cub)
{
	img->floor = (cub->redf << 16) + (cub->greenf << 8) + cub->bluef;
	img->ceilling = (cub->redc << 16) + (cub->greenc << 8) + cub->bluec;
}

void	ft_check_norm(void)
{
	printf("Error: check map!\n");
	exit(1);
}

int	last_char(char *str)
{
	if (!str[0])
		return (0);
	else if (str[ft_strlen(str) - 1] != '1')
		return (0);
	return (1);
}
