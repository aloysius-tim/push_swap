#ifndef FT_PUSH_SWAP_H
#define FT_PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <stdio.h>

//t_list  **ft_generate_stack(int argc, char *argv[]);
int    ft_refractor(t_list *stack);
void print_stacks(t_list *stack_a, t_list *stack_b);
int     ft_push_a_stack_slide(t_list **a_stack, t_list **b_stack, int nb_elems, int iteration);

#endif
