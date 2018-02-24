/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:37:25 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:38:32 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_flags		ft_parse(char **str)
{
	t_flags		flags;
	t_flags		tmp;
	int			option;

	ft_flag_init(&flags);
	while (ft_is_end(**str) && !flags.conv)
	{
		tmp = flags;
		option = 0;
		if ((option = ft_get_options(str)) >= 0)
			flags.options[option] = 1;
		if (ft_is_end(**str) && !flags.width)
			flags.width = ft_get_width(str);
		if (ft_is_end(**str) && flags.precision <= 0)
			flags.precision = ft_get_precision(str);
		if (ft_is_end(**str))
			flags.size_modifier = ft_max(flags.size_modifier,
ft_get_size_modifier(str));
		if (**str)
			flags.conv = ft_get_conv(str, !ft_is_end(**str));
		if (!ft_memcmp(&flags, &tmp, sizeof(t_flags)) && option == -1)
			(*str)++;
	}
	return (flags);
}

void		ft_flag_init(t_flags *flags)
{
	ft_bzero(flags, sizeof(t_flags));
	flags->options = (int*)malloc(sizeof(int) * 5);
	ft_bzero(flags->options, (sizeof(int) * 5));
}

int			ft_is_end(char c)
{
	char *str;
	char *result;

	if (!c)
		return (0);
	str = ft_strdup(". #0-+sScCoOxXdDiuUp\%hjlz");
	result = ft_strchr(str, c);
	free(str);
	if (ft_isdigit(c) || result)
		return (1);
	return (0);
}
