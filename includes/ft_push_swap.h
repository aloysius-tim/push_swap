#ifndef FT_PUSH_SWAP_H
#define FT_PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <stdio.h>

//t_list  **ft_generate_stack(int argc, char *argv[]);
int     ft_refractor(t_list *stack);
void    print_stacks(t_list *stack_a, t_list *stack_b, char *status);
int     ft_push_slides(t_list **a_stack, t_list **b_stack, int slide_size, int iteration, int stack_initial_size,
                       int top_slide, int bottom_slide);
int     ft_push_a_stack_slide(t_list **a_stack, t_list **b_stack, int nb_elems, int slide_size, int list_size);
int     ft_order_stack(t_list  *a_stack, t_list *b_stack);
int     ft_count_rotations_a_inf_b(t_list *a_stack, t_list *b_stack);
int     ft_count_rotations_a_sup_b(t_list *a_stack, t_list *b_stack);
int     ft_rotations_a_inf_b(t_list *a_stack, t_list *b_stack);
int     ft_top_insert(t_list  *a_stack, t_list *b_stack);
int     ft_bottom_insert(t_list  *a_stack, t_list *b_stack);
int     ft_rotate_bottom_insert(t_list  *a_stack, t_list *b_stack);
int     ft_closest_nearest(t_list  *a_stack, t_list *b_stack, int stack_size);
int     ft_is_in_slide(t_list **a_stack, int num_slide, int slide_size, int stack_initial_size);
int    ft_set_on_b_nearest(t_list **a_stack, t_list **b_stack);
int     ft_get_head_less_x(t_list *stack);
int     ft_get_bottom_less_x(t_list *stack);
int     ft_find_nearest_bottom_up(t_list *stack, int top, int bottom, int max_length);
int     ft_find_nearest_up_bottom(t_list *stack, int top, int bottom, int max_length);
void     ft_push_all(t_list **from, t_list **to, int nb_elems);
int     ft_order_three(t_list **a_stack, t_list **b_stack, int nb_elems);
#endif
