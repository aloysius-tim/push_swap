/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:12:40 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/24 14:12:55 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_checker.h"
#include "includes/ft_push_swap.h"

void	ft_op(char *instruction, t_list **a_stack, t_list **b_stack, int nb)
{
	while (nb--)
	{
		ft_handle_instruction(instruction, a_stack, b_stack);
		ft_printf("%s\n", instruction);
	}
}

int		ft_handle_instruction(char *instruction, t_list **a_stack,
t_list **b_stack)
{
	if (ft_strcmp(instruction, "sa") == 0)
		return (ft_swap(a_stack));
	else if (ft_strcmp(instruction, "sb") == 0)
		return (ft_swap(b_stack));
	else if (ft_strcmp(instruction, "ss") == 0)
		return (ft_swap(a_stack) + ft_swap(b_stack));
	else if (ft_strcmp(instruction, "pa") == 0)
		return (ft_push(a_stack, b_stack));
	else if (ft_strcmp(instruction, "pb") == 0)
		return (ft_push(b_stack, a_stack));
	else if (ft_strcmp(instruction, "ra") == 0)
		return (ft_rotate(a_stack, 1));
	else if (ft_strcmp(instruction, "rb") == 0)
		return (ft_rotate(b_stack, 1));
	else if (ft_strcmp(instruction, "rr") == 0)
		return (ft_rotate(a_stack, 1) + ft_rotate(b_stack, 1));
	else if (ft_strcmp(instruction, "rra") == 0)
		return (ft_reverse_rotate(a_stack, 1));
	else if (ft_strcmp(instruction, "rrb") == 0)
		return (ft_reverse_rotate(b_stack, 1));
	else if (ft_strcmp(instruction, "rrr") == 0)
		return (ft_reverse_rotate(a_stack, 1) + ft_reverse_rotate(b_stack, 1));
	else
		exit_error();
	return (0);
}
