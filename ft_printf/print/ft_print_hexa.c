/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:44:55 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:45:17 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_get_diff_hexa(int precision, int size)
{
	int diff;

	diff = 0;
	if (precision != -1)
	{
		diff = precision - size;
		if (diff < 0)
			diff = 0;
	}
	return (diff);
}

int	ft_print_hexa(t_flags conv, int count, unsigned long long int arg)
{
	int result;

	result = 0;
	if (conv.precision != -1)
		result += ft_print_zero(conv.precision -
			ft_get_size_number_base(arg, 16));
	else if (conv.options[OPTION_ZERO] && !conv.options[OPTION_LESS])
		result += ft_print_zero(conv.width - ft_get_size_number_base(arg, 16) -
		count);
	if (conv.precision || arg)
		result += ft_putnbr_base(arg, 16, conv.conv == CONV_HEXA_CAPS);
	return (result);
}

int	ft_print_prefix_hexa(t_flags conv, unsigned long long int arg)
{
	if ((conv.options[OPTION_SHARP] && arg) || conv.conv == CONV_ADRESS)
	{
		if (conv.conv == CONV_HEXA || conv.conv == CONV_ADRESS)
			ft_putstr("0x");
		else
			ft_putstr("0X");
		return (2);
	}
	return (0);
}

int	ft_print_hexa_long_long(unsigned long long int arg, t_flags conv)
{
	int size;
	int count;
	int i;
	int before;
	int diff;

	size = 0;
	count = 0;
	before = 0;
	i = 0;
	if (conv.precision)
		size = ft_max(ft_get_size_number_base(arg, 16), conv.precision);
	diff = ft_get_diff_hexa(conv.precision, size);
	if ((conv.options[OPTION_SHARP] && arg) || conv.conv == CONV_ADRESS)
		before += 2;
	if (!conv.options[OPTION_LESS] && (!conv.options[OPTION_ZERO] ||
		conv.precision != -1))
		count += ft_print_space(conv.width - size - before - diff);
	count += ft_print_prefix_hexa(conv, arg);
	i = count;
	count += ft_print_hexa(conv, count, arg);
	if (conv.options[OPTION_LESS])
		count += ft_print_space(conv.width - size - i);
	return (count);
}
