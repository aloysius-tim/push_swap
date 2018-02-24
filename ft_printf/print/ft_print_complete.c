/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_complete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:44:37 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:44:52 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_space(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int	ft_print_zero(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}
