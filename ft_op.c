/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:02:46 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/24 14:12:33 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_checker.h"

int		ft_swap(t_list **stack)
{
	int tmp;
	int size;

	size = ft_list_size(*stack);
	if (size <= 1)
		return (1);
	tmp = *((int *)ft_list_at(*stack, 0)->data);
	*((int *)ft_list_at(*stack, 0)->data) =
*((int*)ft_list_at(*stack, 1)->data);
	*((int*)ft_list_at(*stack, 1)->data) = tmp;
	return (1);
}

int		ft_push(t_list **stack_a, t_list **stack_b)
{
	if ((ft_list_size(*stack_b)) == 0)
		return (1);
	ft_list_push_front(stack_a, ft_list_pop(stack_b));
	return (1);
}

int		ft_rotate(t_list **stack, int nb)
{
	void	*tmp;
	int		counter;

	counter = nb;
	if (!stack || !(*stack) || ft_list_size(*stack) < 1)
		return (1);
	while (nb--)
	{
		tmp = ft_list_pop(stack);
		ft_list_push_back(stack, tmp);
	}
	return (counter);
}

int		ft_reverse_rotate(t_list **stack, int nb)
{
	void	*tmp;
	int		counter;

	counter = nb;
	if (!stack || !(*stack) || ft_list_size(*stack) < 1)
		return (1);
	while (nb--)
	{
		tmp = ft_list_pop_last(stack);
		ft_list_push_front(stack, tmp);
	}
	return (counter);
}
