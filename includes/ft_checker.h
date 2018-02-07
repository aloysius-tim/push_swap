#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <stdio.h>

int     ft_swap(t_list** stack);
int     ft_swap_both(t_list** stack_a, t_list** stack_b);
int     ft_push_a(t_list** stack_a, t_list** stack_b);
int     ft_push_b(t_list** stack_a, t_list** stack_b);
int     ft_rotate(t_list** stack);
int     ft_rotate_both(t_list** stack_a, t_list** stack_b);
int     ft_reverse_rotate(t_list** stack);
int     ft_reverse_rotate_both(t_list** stack_a, t_list** stack_b);
#endif