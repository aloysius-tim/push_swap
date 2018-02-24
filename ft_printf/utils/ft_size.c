/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:48:03 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:48:12 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_get_size_number_long_long(long long int n)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

int		ft_get_size_number(int n)
{
	return (ft_get_size_number_long_long((long long int)n));
}

int		ft_get_size_number_long_long_unsigned(unsigned long long int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

int		ft_get_size_number_base(unsigned long long int n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}
