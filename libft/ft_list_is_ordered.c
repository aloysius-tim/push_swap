/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:29:26 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/24 13:23:01 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

int		ft_list_is_ordered_int(t_list *begin_list)
{
	int current;

	current = *((int*)begin_list->data);
	while (begin_list->next)
	{
		if (*((int*)begin_list->next->data) < current)
			return (0);
		current = *((int*)begin_list->next->data);
		begin_list = begin_list->next;
	}
	return (1);
}

int		ft_list_is_reverse_ordered_int(t_list *begin_list)
{
	int current;

	current = *((int*)begin_list->data);
	while (begin_list->next)
	{
		if (*((int*)begin_list->next->data) > current)
			return (0);
		current = *((int*)begin_list->next->data);
		begin_list = begin_list->next;
	}
	return (1);
}

int		ft_list_has_duplicates_int(t_list *begin_list)
{
	t_list	*head;

	head = begin_list;
	while (begin_list)
	{
		if (ft_list_contain_duplicate_int(head,
*((int *)begin_list->data)) == 1)
			return (1);
		begin_list = begin_list->next;
	}
	return (0);
}

int		ft_list_contain_duplicate_int(t_list *begin_list, int nb)
{
	int		counter;

	counter = 0;
	while (begin_list)
	{
		if (*((int *)begin_list->data) == nb)
			counter++;
		begin_list = begin_list->next;
	}
	if (counter <= 1)
		return (0);
	else
		return (1);
}
