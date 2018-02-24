#include "includes/ft_push_swap.h"
#include "includes/ft_checker.h"

int     ft_is_in_slide(t_list **a_stack, int num_slide, int slide_size, int stack_initial_size)
{
    int max_top;
    int max_bottom;
    int min_top;
    int min_bottom;

    max_top = num_slide * slide_size;
    min_top = max_top - slide_size;
    min_bottom = stack_initial_size - max_top;
    max_bottom = stack_initial_size - min_top;
    if ((*((int *)((*a_stack)->data)) >= min_top && *((int *)((*a_stack)->data)) <= max_top) || (*((int *)((*a_stack)
            ->data)) >= min_bottom && *((int *)((*a_stack)->data)) <= max_bottom))
        return (1);
    return (0);
}

int     ft_push_slides(t_list **a_stack, t_list **b_stack, int slide_size, int iteration, int stack_initial_size,
                       int top_slide, int bottom_slide)
{
    int     counter;
    int     stack_size;

    counter = 0;
    stack_size = ft_list_size(*a_stack);
    if (stack_size == 0)
        return (counter);
    while (counter < stack_size)
    {
        if (ft_is_in_slide(a_stack, bottom_slide, slide_size, stack_initial_size))
            ft_op("pb", a_stack, b_stack, 1);
        else if (ft_is_in_slide(a_stack, top_slide, slide_size, stack_initial_size))
        {
            ft_op("pb", a_stack, b_stack, 1);
            ft_op("rb", a_stack, b_stack, 1);
        } else
            ft_op("ra", a_stack, b_stack, 1);
        counter++;
    }
    return (ft_push_slides(a_stack, b_stack, slide_size, iteration + 1, stack_initial_size, top_slide - 1,
                           bottom_slide + 1));
}

void     ft_push_all(t_list **from, t_list **to, int nb_elems)
{
    int counter;

    counter = nb_elems - 2;
    while (--counter)
        ft_op("pb", from, to, 1);
    if (!ft_list_is_ordered_int(*from))
        ft_order_three(from, to, nb_elems);
}

int    ft_refractor(t_list *stack)
{
    t_list  *head;
    int     nb_elem;

    nb_elem = 0;
    head = stack;
    while (stack && ++nb_elem)
    {
        if (!((stack->content) = (int *) malloc(sizeof(int))))
            return (0);
        *((int *)stack->content) = ft_list_get_nb_smaller(head, stack) + 1;
        stack = stack->next;
    }
    stack = head;
    while (stack)
    {
        *((int *)stack->data) = *((int *)stack->content);
        free(((int *)stack->content));
        stack = stack->next;
    }
    return (nb_elem);
}