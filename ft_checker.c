/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:56:22 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/24 14:01:06 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_checker.h"

int		main(int argc, char *argv[])
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		*tmp;
	char	*current_instruction;

	if (argc == 1)
		return (0);
	while (--argc)
	{
		if (!(tmp = (int *)malloc(sizeof(int))))
			return (0);
		if (!ft_isdigit(*argv[argc]))
			exit_error();
		*tmp = ft_atoi(argv[argc]);
		ft_list_push_front(&a_stack, tmp);
	}
	if (ft_list_has_duplicates_int(a_stack))
		exit_error();
	while (get_next_line(0, &current_instruction))
		ft_handle_instruction(current_instruction, &a_stack, &b_stack);
	(ft_list_is_ordered_int(a_stack)) ? ft_printf("OK\n") : ft_printf("KO\n");
	ft_list_clear(&a_stack);
	ft_list_clear(&b_stack);
	return (1);
}
