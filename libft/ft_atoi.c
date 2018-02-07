/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 13:20:41 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/15 13:59:33 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int		neg;
	int		nb_long;
	int		tmp;

	neg = 1;
	nb_long = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' ||
			*str == '\f' || *str == '\v')
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nb_long *= 10;
		tmp = *str - 48;
		nb_long += tmp;
		str++;
	}
	return ((int)nb_long * neg);
}
