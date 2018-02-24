/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:38:49 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:39:49 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_print_2(va_list arg, t_flags flag)
{
	if ((flag.conv == CONV_UNSIGNED_INT && flag.size_modifier == SIZE_LONG) ||
			(flag.conv == CONV_UNSIGNED_LONG_INT) ||
			(flag.conv == CONV_OCTAL && flag.size_modifier == SIZE_LONG) ||
			(flag.conv == CONV_HEXA && flag.size_modifier == SIZE_LONG) ||
			(flag.conv == CONV_HEXA_CAPS && flag.size_modifier == SIZE_LONG) ||
			(flag.conv == CONV_ADRESS))
		return (ft_print_long_long_int_unsigned((unsigned long long int)(va_arg(
arg, unsigned long int)), flag));
	else if ((flag.conv == CONV_UNSIGNED_INT
				&& flag.size_modifier == SIZE_LONG_LONG) ||
			(flag.conv == CONV_OCTAL && flag.size_modifier == SIZE_LONG_LONG) ||
			(flag.conv == CONV_HEXA && flag.size_modifier == SIZE_LONG_LONG) ||
			(flag.conv == CONV_HEXA_CAPS &&
flag.size_modifier == SIZE_LONG_LONG))
		return (ft_print_long_long_int_unsigned(
					va_arg(arg, unsigned long long int), flag));
	else if (flag.size_modifier == SIZE_INT_MAX)
		return (ft_print_int_max(va_arg(arg, intmax_t), flag));
	else if (flag.size_modifier == SIZE_SIZE_T)
		return (ft_print_sizet(va_arg(arg, size_t), flag));
	else if (flag.conv == CONV_NONE)
		return (ft_print_none(flag));
	else
		return (ft_print_c_char(flag.conv, flag));
}

int			ft_print(va_list arg, t_flags flag)
{
	if (flag.conv == CONV_CHAR)
		return (ft_print_c_char(va_arg(arg, int), flag));
	else if (flag.conv == CONV_STRING)
		return (ft_print_string(va_arg(arg, wchar_t*), flag));
	else if (flag.conv == CONV_INT && (flag.size_modifier == SIZE_CHAR ||
				flag.size_modifier == SIZE_SHORT || !flag.size_modifier))
		return (ft_print_int(va_arg(arg, int), flag));
	else if (flag.conv == CONV_INT && flag.size_modifier == SIZE_LONG)
		return (ft_print_long_long_int((long long int)va_arg(arg, long int),
					flag));
	else if (flag.conv == CONV_INT && flag.size_modifier == SIZE_LONG_LONG)
		return (ft_print_long_long_int(va_arg(arg, long long int), flag));
	else if ((flag.conv == CONV_UNSIGNED_INT || flag.conv == CONV_OCTAL ||
				flag.conv == CONV_HEXA || flag.conv == CONV_HEXA_CAPS)
			&& (!flag.size_modifier || flag.size_modifier == SIZE_CHAR ||
				flag.size_modifier == SIZE_SHORT))
		return (ft_print_int_unsigned(va_arg(arg, unsigned int), flag));
	return (ft_print_2(arg, flag));
}
