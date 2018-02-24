/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:56:25 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:51:52 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_print_unicode_4(unsigned int c, unsigned int mask)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
	unsigned char	octet;

	o1 = ((c >> 18) << 29) >> 29;
	o2 = ((c >> 12) << 26) >> 26;
	o3 = ((c >> 6) << 26) >> 26;
	o4 = (c << 26) >> 26;
	octet = (mask >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o4;
	write(1, &octet, 1);
	return (4);
}

static int	ft_print_unicode_3(unsigned int c, unsigned int mask)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	octet;

	o1 = ((c >> 12) << 28) >> 28;
	o2 = ((c >> 6) << 26) >> 26;
	o3 = (c << 26) >> 26;
	octet = (mask >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o3;
	write(1, &octet, 1);
	return (3);
}

static int	ft_print_unicode_2(unsigned int c, unsigned int mask)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	octet;

	o1 = ((c >> 6) << 27) >> 27;
	o2 = (c << 26) >> 26;
	octet = (mask >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o2;
	write(1, &octet, 1);
	return (2);
}

int			ft_size_binary(wchar_t i)
{
	int		result;
	wchar_t	mask;

	mask = 1;
	result = 0;
	if (i < 2)
		return (1);
	while (i >= mask)
	{
		result++;
		mask <<= 1;
		if (mask == 0)
			return (sizeof(wchar_t));
	}
	return (result);
}

int			ft_print_unicode(wchar_t c)
{
	int	size;

	size = ft_size_binary(c);
	if (size < 8)
		return (write(1, &c, 1));
	else if (size < 12)
		return (ft_print_unicode_2((unsigned int)c, 49280));
	else if (size < 17)
		return (ft_print_unicode_3((unsigned int)c, 14712960));
	return (ft_print_unicode_4((unsigned int)c, 4034953344));
}
