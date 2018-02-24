/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:33:05 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:33:32 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			count;
	va_list		arg;

	va_start(arg, str);
	if (!(*str))
		return (0);
	count = ft_read(arg, (char*)str);
	va_end(arg);
	return (count);
}

int	ft_read(va_list arg, char *str)
{
	t_flags		flags;
	int			count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flags = ft_parse(&(str));
			if (flags.conv)
			{
				ft_flag_optm(&flags);
				count += ft_print(arg, flags);
			}
			free(flags.options);
		}
		else
		{
			ft_putchar(*str);
			count++;
			str++;
		}
	}
	return (count);
}
