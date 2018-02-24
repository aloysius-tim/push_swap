/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_optm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:33:55 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:36:36 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_flag_optm2(t_flags *flags)
{
	if (flags->conv == CONV_CHAR_CAPS)
	{
		flags->conv = CONV_CHAR;
		flags->size_modifier = SIZE_LONG;
	}
	if (flags->conv == CONV_CHAR && flags->size_modifier != SIZE_LONG)
		flags->size_modifier = 0;
	if (flags->conv == CONV_STRING_CAPS)
	{
		flags->conv = CONV_STRING;
		flags->size_modifier = SIZE_LONG;
	}
	if (flags->conv == CONV_STRING && flags->size_modifier != SIZE_LONG)
		flags->size_modifier = 0;
	if (flags->conv == CONV_OCTAL_CAPS)
	{
		flags->conv = CONV_OCTAL;
		flags->size_modifier = SIZE_LONG;
	}
}

void		ft_flag_optm(t_flags *flags)
{
	if (flags->conv == CONV_LONG_INT && flags->size_modifier)
	{
		flags->conv = CONV_INT;
		flags->size_modifier = SIZE_LONG;
	}
	else if (flags->conv == CONV_LONG_INT && !flags->size_modifier)
	{
		flags->conv = CONV_INT;
		flags->size_modifier = SIZE_LONG;
	}
	if (flags->conv == CONV_UNSIGNED_LONG_INT && flags->size_modifier)
	{
		flags->conv = CONV_UNSIGNED_LONG_INT;
		flags->size_modifier = SIZE_LONG;
	}
	else if (flags->conv == CONV_UNSIGNED_LONG_INT && !flags->size_modifier)
	{
		flags->conv = CONV_UNSIGNED_INT;
		flags->size_modifier = SIZE_LONG;
	}
	ft_flag_optm2(flags);
}

int			ft_get_size_modifier_2(char **str)
{
	if (**str == 'j')
	{
		(*str)++;
		return (SIZE_INT_MAX);
	}
	else if (**str == 'z')
	{
		(*str)++;
		return (SIZE_SIZE_T);
	}
	return (0);
}
