/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:29:26 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/16 18:17:49 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_list_is_ordered_int(t_list *begin_list)
{
	int previous;

    previous = *((int*)begin_list->data);
	while (begin_list->next)
	{
		if (*((int*)begin_list->data) < previous)
			return (0);
        previous = *((int*)begin_list->data);
		begin_list = begin_list->next;
	}
	return (1);
}
