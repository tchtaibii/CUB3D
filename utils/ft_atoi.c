/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 07:47:26 by iel-mach          #+#    #+#             */
/*   Updated: 2022/06/25 08:53:17 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_atoi(char *s)
{
	int				sign;
	unsigned long	rus;

	sign = 1;
	rus = 0;
	while (*s == 32 || (*s >= 7 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= (-1);
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		rus = (rus * 10) + (*s - 48);
		if (rus > 9223372036854775807 && sign == -1)
			return (0);
		else if (rus > 9223372036854775807 && sign == 1)
			return (-1);
		s++;
	}
	return (sign * rus);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
