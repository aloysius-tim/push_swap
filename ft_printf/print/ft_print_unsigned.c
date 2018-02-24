/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:46:38 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:47:10 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_int_unsigned(unsigned int arg, t_flags conv)
{
	unsigned short int tmp;

	if (conv.size_modifier == SIZE_CHAR)
	{
		tmp = (unsigned char)arg;
		return (ft_print_long_long_int_unsigned((long long unsigned int)tmp,
					conv));
	}
	else if (conv.size_modifier == SIZE_SHORT)
	{
		tmp = (unsigned short int)arg;
		return (ft_print_long_long_int_unsigned((long long unsigned int)tmp,
					conv));
	}
	return (ft_print_long_long_int_unsigned((unsigned long long int)arg, conv));
}

int	ft_print_unsigned(t_flags conv, int count, int size,
unsigned long long int arg)
{
	int result;

	result = 0;
	if (conv.precision != -1)
		result += ft_print_zero(conv.precision -
				ft_get_size_number_long_long_unsigned(arg));
	else if (conv.options[OPTION_ZERO] && !conv.options[OPTION_LESS])
		result += ft_print_zero(conv.width - size - count);
	if (conv.precision || arg)
	{
		ft_putnbr_unsigned_long_long(arg);
		result += ft_get_size_number_long_long_unsigned(arg);
	}
	return (result);
}

int	ft_get_diff_unsigned(t_flags conv, unsigned long long int arg)
{
	int diff;

	diff = 0;
	if (conv.precision != -1)
	{
		diff = conv.precision - ft_get_size_number_long_long_unsigned(arg);
		if (diff < 0)
			diff = 0;
	}
	return (diff);
}

int	ft_print_long_long_int_unsigned(unsigned long long int arg,
t_flags conv)
{
	int size;
	int count;
	int i;
	int diff;

	count = 0;
	if (conv.conv == CONV_HEXA || conv.conv == CONV_HEXA_CAPS ||
			conv.conv == CONV_ADRESS)
		return (ft_print_hexa_long_long(arg, conv));
	else if (conv.conv == CONV_OCTAL)
		return (ft_print_octal_long_long(arg, conv));
	diff = ft_get_diff_unsigned(conv, arg);
	size = ft_max(ft_get_size_number_long_long_unsigned(arg), conv.precision);
	if (!conv.options[OPTION_LESS]
			&& (!conv.options[OPTION_ZERO] || conv.precision != -1))
		count += ft_print_space(conv.width -
				ft_get_size_number_long_long_unsigned(arg) - diff);
	i = count;
	count += ft_print_unsigned(conv, count, size, arg);
	if (conv.options[OPTION_LESS])
		count += ft_print_space(conv.width - size - i);
	return (count);
}
