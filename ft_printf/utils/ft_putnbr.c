/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:47:48 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:47:57 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_putnbr_long_long(long long int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_long_long(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
	return (1);
}

int		ft_putnbr_unsigned_long_long(unsigned long long int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned_long_long(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
	return (1);
}

int		ft_putnbr_unsigned(unsigned int nb)
{
	return (ft_putnbr_unsigned_long_long((unsigned long long int)nb));
}

void	ft_putstr_reverse(char *str, int size)
{
	while (size > 0)
	{
		ft_putchar(str[size - 1]);
		size--;
	}
}

int		ft_putnbr_base(unsigned long long int i, int base, int caps)
{
	char	tmp[34];
	char	*hex;
	int		cpt;

	if (i == 0)
	{
		ft_putchar('0');
		return (1);
	}
	cpt = 0;
	if (caps)
		hex = ft_strdup("0123456789ABCDEF");
	else
		hex = ft_strdup("0123456789abcdef");
	while (i)
	{
		tmp[cpt] = hex[i % base];
		i = i / base;
		cpt++;
	}
	ft_putstr_reverse(tmp, cpt);
	free(hex);
	return (cpt);
}
