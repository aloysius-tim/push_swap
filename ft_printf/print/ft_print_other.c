/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:46:15 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:46:33 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_print_int_max(intmax_t arg, t_flags conv)
{
	if (conv.conv == CONV_HEXA)
		return (ft_print_hexa_long_long((unsigned long long)arg, conv));
	if (conv.conv == CONV_OCTAL)
		return (ft_print_octal_long_long((unsigned long long)arg, conv));
	if (conv.conv == CONV_INT)
		return (ft_print_long_long_int((unsigned long long int)arg, conv));
	return (ft_print_long_long_int_unsigned((unsigned long long int)arg, conv));
}

int			ft_print_sizet(size_t arg, t_flags conv)
{
	if (conv.conv == CONV_HEXA)
		return (ft_print_hexa_long_long((unsigned long long)arg, conv));
	if (conv.conv == CONV_OCTAL)
		return (ft_print_octal_long_long((unsigned long long)arg, conv));
	if (conv.conv == CONV_INT)
		return (ft_print_long_long_int((unsigned long long int)arg, conv));
	return (ft_print_long_long_int_unsigned((unsigned long long int)arg, conv));
}

int			ft_print_none(t_flags conv)
{
	int count;

	count = 0;
	if (!conv.options[OPTION_LESS])
	{
		if (conv.options[OPTION_ZERO])
			count += ft_print_zero(conv.width - 1);
		else
			count += ft_print_space(conv.width - 1);
	}
	count += ft_putchar('%');
	if (conv.options[OPTION_LESS])
		count += ft_print_space(conv.width - 1);
	return (count);
}
