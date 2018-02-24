/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:34:37 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:37:09 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_get_options(char **str)
{
	char	*available_options;
	char	*option_ptr;

	available_options = ft_strdup("#0-+ ");
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+'
			|| **str == ' ')
	{
		option_ptr = ft_strchr(available_options, **str);
		(*str)++;
		free(available_options);
		return (option_ptr - available_options);
	}
	free(available_options);
	return (-1);
}

int			ft_get_width(char **str)
{
	int result;

	if (**str == '0' || **str == '-' || **str == '+')
		return (0);
	result = ft_atoi(*str);
	if (result)
	{
		(*str) += ft_get_size_number(result);
		return (result);
	}
	return (0);
}

int			ft_get_precision(char **str)
{
	int result;

	if (**str == '.')
	{
		(*str)++;
		result = ft_atoi(*str);
		if (result || **str == '0')
		{
			(*str) += ft_get_size_number(result);
			return (result);
		}
		return (0);
	}
	return (-1);
}

int			ft_get_size_modifier(char **str)
{
	if (**str == 'h')
	{
		(*str)++;
		if (**str == 'h')
		{
			(*str)++;
			return (SIZE_CHAR);
		}
		return (SIZE_SHORT);
	}
	else if (**str == 'l')
	{
		(*str)++;
		if (**str == 'l')
		{
			(*str)++;
			return (SIZE_LONG_LONG);
		}
		return (SIZE_LONG);
	}
	return (ft_get_size_modifier_2(str));
}

int			ft_get_conv(char **str, int force)
{
	char	*tmp;
	char	*conv;
	int		result;

	if (**str == 'i')
	{
		(*str)++;
		return (CONV_INT);
	}
	conv = ft_strdup("sScCoOxXdDuUp\%");
	tmp = ft_strchr(conv, **str);
	free(conv);
	if (tmp)
	{
		(*str)++;
		result = tmp - conv + 1;
		return (result);
	}
	else if (force)
	{
		(*str)++;
		return ((*(*str - 1)));
	}
	return (0);
}
