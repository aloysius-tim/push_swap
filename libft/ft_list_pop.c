/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:29:38 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/16 18:18:35 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_list_pop(t_list **begin_list)
{
	void    *val;
    t_list  *tmp;

	if (!begin_list)
		return (0);
	val = ((int *)ft_list_at(*begin_list, 0)->data);
    tmp = *begin_list;
	*begin_list = (*begin_list)->next;
    //free(tmp->data);
    free(tmp);
	return (val);
}

void	*ft_list_pop_last(t_list **begin_list)
{
    void *val;

    ft_list_reverse(begin_list);
    val = ft_list_pop(begin_list);
    ft_list_reverse(begin_list);
    return (val);
}
