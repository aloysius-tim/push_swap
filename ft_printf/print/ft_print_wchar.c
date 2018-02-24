/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:47:20 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:47:31 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr_w(wchar_t *str, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] && count <= size)
	{
		if (ft_len_w(str[i]) <= size - count)
			count += ft_print_unicode(str[i]);
		i++;
	}
	return (count);
}

int	ft_len_w(wchar_t va)
{
	int size;

	size = ft_size_binary((unsigned int)va);
	if (size <= 7)
		return (1);
	else if (size <= 11)
		return (2);
	else if (size <= 16)
		return (3);
	return (4);
}

int	ft_strlen_w(wchar_t *str)
{
	int i;
	int size;

	if (!str)
		return (0);
	i = 0;
	size = 0;
	while (str[i])
	{
		size += ft_len_w(str[i]);
		i++;
	}
	return (size);
}

int	ft_strclen_w(wchar_t *str, int size)
{
	int i;
	int count;

	count = 0;
	if (!str)
		return (0);
	i = 0;
	while (str[i] && count < size)
	{
		if (ft_len_w(str[i]) <= size - count)
			count += ft_len_w(str[i]);
		i++;
	}
	return (count);
}
