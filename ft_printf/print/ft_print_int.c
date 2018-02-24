/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:45:21 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:45:50 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_int(int arg, t_flags conv)
{
	short int tmp;

	if (conv.size_modifier == SIZE_CHAR)
	{
		tmp = (char)arg;
		return (ft_print_long_long_int((long long int)tmp, conv));
	}
	else if (conv.size_modifier == SIZE_SHORT)
	{
		tmp = (short int)arg;
		return (ft_print_long_long_int((long long int)tmp, conv));
	}
	return (ft_print_long_long_int((long long int)arg, conv));
}

int	ft_get_diff_int(long long int arg, t_flags conv, int size_number)
{
	int diff;

	diff = 0;
	if (conv.precision != -1)
	{
		if (arg >= 0)
			diff = conv.precision - size_number;
		else
			diff = conv.precision - size_number + 1;
		if (diff < 0)
			diff = 0;
	}
	return (diff);
}

int	ft_print_prefix_int(t_flags conv, long long int arg)
{
	if (conv.options[OPTION_PLUS] && arg >= 0)
		return (ft_putchar('+'));
	else if (conv.options[OPTION_SPACE] && arg >= 0)
		return (ft_putchar(' '));
	return (0);
}

int	ft_print_number(long long int arg, t_flags conv, int size,
	int before)
{
	int count;

	count = 0;
	if (arg < 0)
	{
		ft_putchar('-');
		if (conv.precision != -1)
			count += ft_print_zero(conv.precision -
				ft_get_size_number_long_long(-arg));
		else if (conv.options[OPTION_ZERO] && !conv.options[OPTION_LESS])
			count += ft_print_zero(conv.width - size - before);
		if (arg || conv.precision)
			ft_putnbr_unsigned_long_long((unsigned long long int)-arg);
	}
	else
	{
		if (conv.precision != -1)
			count += ft_print_zero(conv.precision -
				ft_get_size_number_long_long(arg));
		else if (conv.options[OPTION_ZERO] && !conv.options[OPTION_LESS])
			count += ft_print_zero(conv.width - size - before);
		if (arg || conv.precision)
			ft_putnbr_unsigned_long_long((unsigned long long int)arg);
	}
	return (count);
}

int	ft_print_long_long_int(long long int arg, t_flags conv)
{
	int size;
	int count;
	int i;
	int size_number;
	int diff;

	size_number = 0;
	count = 0;
	if (arg || conv.precision > 0)
		size_number = ft_get_size_number_long_long(arg);
	diff = ft_get_diff_int(arg, conv, size_number);
	size_number += ((conv.options[OPTION_SPACE] ||
					conv.options[OPTION_PLUS]) && arg >= 0);
	size = ft_max(ft_get_size_number_long_long(arg), conv.precision);
	if (!conv.options[OPTION_LESS] && (!conv.options[OPTION_ZERO] ||
		conv.precision != -1))
		count += ft_print_space(conv.width - size_number - diff);
	count += ft_print_prefix_int(conv, arg);
	i = count;
	count += ft_print_number(arg, conv, size, count);
	if (arg || conv.precision)
		count += ft_get_size_number_long_long(arg);
	if (conv.options[OPTION_LESS])
		count += ft_print_space(conv.width - size - i);
	return (count);
}
