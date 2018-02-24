/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:29:38 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/24 12:28:28 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_print_int(t_list *begin_list)
{
	while (begin_list)
	{
		ft_putnbr(*((int *)(begin_list->data)));
		ft_putchar('\n');
		begin_list = begin_list->next;
	}
}
