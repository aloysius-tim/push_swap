/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:40:01 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:44:33 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_print_c_char(int arg, t_flags flag)
{
	int count;

	count = 0;
	if (!flag.options[OPTION_LESS])
	{
		if (flag.options[OPTION_ZERO])
			count += ft_print_zero(flag.width - 1);
		else
			count += ft_print_space(flag.width - 1);
	}
	if (flag.size_modifier == SIZE_LONG)
		count += ft_print_unicode(arg);
	else
		count += ft_putchar((char)arg);
	if (flag.options[OPTION_LESS])
		count += ft_print_space(flag.width - 1);
	return (count);
}

int			ft_get_size(t_flags flag, int *arg)
{
	int size;

	if (flag.size_modifier == SIZE_LONG)
		size = ft_strlen_w(arg);
	else
		size = ft_strlen((char*)arg);
	if (flag.precision != -1)
	{
		if (flag.size_modifier == SIZE_LONG)
			size = ft_strclen_w(arg, ft_min(ft_strlen_w(arg), flag.precision));
		else
			size = ft_min(ft_strlen((char*)arg), flag.precision);
	}
	return (size);
}

int			ft_print_string(int *arg, t_flags flag)
{
	int size;
	int count;

	count = 0;
	size = ft_get_size(flag, arg);
	if (!flag.options[OPTION_LESS])
	{
		if (flag.options[OPTION_ZERO])
			count += ft_print_zero(flag.width - size);
		else
			count += ft_print_space(flag.width - size);
	}
	if (!arg && flag.precision)
		count += ft_putstr("(null)");
	else if (arg && flag.precision)
	{
		if (flag.size_modifier == SIZE_LONG)
			count += ft_putstr_w(arg, size);
		else
			count += write(1, arg, size);
	}
	if (flag.options[OPTION_LESS])
		count += ft_print_space(flag.width - size);
	return (count);
}
