/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:13:19 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/24 14:14:16 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"
#include "includes/ft_checker.h"

void	ft_order_stack(t_list **a_stack, t_list **b_stack)
{
	if (ft_list_size(*a_stack) == 0)
		ft_op("pa", a_stack, b_stack, 1);
	while (ft_list_size(*b_stack) != 0)
	{
		ft_set_on_b_nearest(a_stack, b_stack);
		if (*((int *)(*b_stack)->data) < *((int *)ft_list_at(*a_stack,
(ft_list_size(*a_stack) / 2))->data) || *((int *)
					(*b_stack)->data) < *((int*)(*a_stack)->data))
			ft_insert_top(a_stack, b_stack);
		else
			ft_insert_bottom(a_stack, b_stack);
	}
}

int		ft_order_three(t_list **a_stack, t_list **b_stack, int nb_elems)
{
	t_list *stack;

	stack = *a_stack;
	if (*((int *)stack->data) > *((int *)stack->next->data))
		(ft_op("sa", a_stack, b_stack, 1));
	if (ft_list_is_reverse_ordered_int(*a_stack))
	{
		(ft_op("rra", a_stack, b_stack, nb_elems));
		return (1);
	}
	if (ft_list_is_ordered_int(*a_stack))
		return (1);
	(ft_op("rra", a_stack, b_stack, 1));
	if (ft_list_is_ordered_int(*a_stack))
		return (1);
	(ft_op("sa", a_stack, b_stack, 1));
	return (1);
}

int		ft_set_on_b_nearest(t_list **a_stack, t_list **b_stack)
{
	int max_length;
	int top;
	int bottom;
	int bottom_up;
	int up_bottom;

	if (!a_stack || !b_stack)
		return (0);
	max_length = 4;
	top = *((int *)ft_list_at(*a_stack, ft_get_head_less_x(*a_stack))->data);
	bottom = *((int *)ft_list_at(*a_stack,
ft_get_bottom_less_x(*a_stack))->data);
	bottom_up = ft_find_nearest_bottom_up(*b_stack, top, bottom, max_length);
	up_bottom = ft_find_nearest_up_bottom(*b_stack, top, bottom, max_length);
	if (bottom_up < up_bottom)
	{
		ft_op("rrb", a_stack, b_stack, bottom_up);
		return (bottom_up);
	}
	else
	{
		ft_op("rb", a_stack, b_stack, up_bottom);
		return (up_bottom);
	}
}
