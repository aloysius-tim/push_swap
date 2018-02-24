/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:45:53 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:46:11 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_get_diff_octal(int precision, int size)
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

int	ft_print_octal(t_flags conv, int count, int before,
unsigned long long int arg)
{
	int result;

	result = 0;
	if (conv.precision != -1)
		result += ft_print_zero(conv.precision -
			ft_get_size_number_base(arg, 8) - before);
	else if (conv.options[OPTION_ZERO] && !conv.options[OPTION_LESS])
		result += ft_print_zero(conv.width - ft_get_size_number_base(arg, 8) -
		count);
	if (conv.precision || arg || conv.options[OPTION_SHARP])
		result += ft_putnbr_base(arg, 8, 0);
	return (result);
}

int	ft_print_octal_long_long(unsigned long long int arg, t_flags conv)
{
	int size;
	int count;
	int i;
	int diff;
	int before;

	size = 0;
	count = 0;
	before = 0;
	i = 0;
	if (conv.precision)
		size = ft_max(ft_get_size_number_base(arg, 8), conv.precision);
	diff = ft_get_diff_octal(conv.precision, size);
	if (conv.options[OPTION_SHARP] && arg)
		before += 1;
	if (!conv.options[OPTION_LESS] && (!conv.options[OPTION_ZERO] ||
		conv.precision != -1))
		count += ft_print_space(conv.width - size - before - diff);
	if (conv.options[OPTION_SHARP] && arg)
		count += ft_putchar('0');
	i = count;
	count += ft_print_octal(conv, count, before, arg);
	if (conv.options[OPTION_LESS])
		count += ft_print_space(conv.width - size - i);
	return (count);
}
