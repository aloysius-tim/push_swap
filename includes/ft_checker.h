/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:40:47 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/24 14:41:42 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include "../libft/includes/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <stdio.h>

int		exit_error();
int		ft_swap(t_list **stack);
int		ft_push(t_list **stack_a, t_list **stack_b);
int		ft_rotate(t_list **stack, int nb);
int		ft_reverse_rotate(t_list **stack, int nb);
int		ft_handle_instruction(char *instruction, t_list **a_stack,
t_list **b_stack);
void	ft_op(char *instruction, t_list **a_stack, t_list **b_stack, int nb_op);
#endif
