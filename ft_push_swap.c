#include "includes/ft_push_swap.h"
#include "includes/ft_checker.h"

int     main(int argc, char *argv[])
{
    t_list  *a_stack;
    t_list  *b_stack;
    int     *tmp;
    int     nb_elems;
    int     nb_slides;

    nb_elems = 0;
    if (argc == 1)
        return (0);
    while (--argc && ++nb_elems) {
        if (!(tmp = (int *) malloc(sizeof(int))))
            return (0);
        *tmp = ft_atoi(argv[argc]);
        ft_list_push_front(&a_stack, tmp);
    }
    if (nb_elems == 1 || ft_list_is_ordered_int(a_stack))
        return (1);
    nb_elems = ft_refractor(a_stack);
    nb_slides = ((nb_elems <= 10) ? 1 : ft_ceil(8 + (nb_elems / 200) * 2));
    (nb_slides != 1) ? ft_push_slides(&a_stack, &b_stack, nb_elems / nb_slides, 1, nb_elems, nb_slides / 4,
                                      nb_slides / 4 + 1) : ft_push_all(&a_stack, &b_stack, nb_elems);
    ft_order_stack(&a_stack, &b_stack);
    ft_list_clear(&a_stack);
    ft_list_clear(&b_stack);
    return (1);
}

int     ft_order_three(t_list **a_stack, t_list **b_stack, int nb_elems)
{
    t_list *stack;

    stack = *a_stack;
    if (*((int *)stack->data) > *((int *)stack->next->data))
        (ft_op("sa", a_stack, b_stack, 1));
    if (ft_list_is_reverse_ordered_int(*a_stack))
        return (ft_op("rra", a_stack, b_stack, nb_elems));
    if (ft_list_is_ordered_int(*a_stack))
        return (1);
    (ft_op("rra", a_stack, b_stack, 1));
    if (ft_list_is_ordered_int(*a_stack))
        return (1);
    (ft_op("sa", a_stack, b_stack, 1));
    return (1);
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

int     ft_get_head_less_x(t_list *stack)
{
    int     current_pos;

    if (!stack)
        return 0;
    current_pos = ft_list_size(stack) / 2;
    while (current_pos != 0 &&
            *((int *)ft_list_at(stack, current_pos)->data) - *((int *)ft_list_at(stack, current_pos - 1)->data) == 1)
        current_pos--;
    return (current_pos);
}

int     ft_get_bottom_less_x(t_list *stack)
{
    int current_pos;

    if (!stack)
        return 0;
    current_pos = ft_list_size(stack) / 2;
    while (current_pos != ft_list_size(stack) - 1
           && *((int *)ft_list_at(stack, current_pos + 1)->data) - *((int *)ft_list_at(stack, current_pos)->data) == 1)
        current_pos++;
    return (current_pos);
}

int     ft_find_nearest_up_bottom(t_list *stack, int top, int bottom, int max_length)
{
    int counter;

    counter = 0;
    if (!stack)
        return 0;
    while (stack)
    {
        if ((*((int *)(stack)->data) <= top && *((int *)(stack)->data) >= top - max_length) ||
            (*((int *)(stack)->data) > bottom && *((int *)(stack)->data) <= bottom + max_length))
            break;
        counter++;
        stack = (stack)->next;
    }
    return (counter);
}

int     ft_find_nearest_bottom_up(t_list *stack, int top, int bottom, int max_length)
{
    int counter;
    int pos;

    pos = ft_list_size(stack) - 1;
    counter = 0;
    if (!stack || pos == 0)
        return 0;
    while (pos)
    {
        if ((*((int *)(ft_list_at(stack, pos))->data) <= top && *((int *)(ft_list_at(stack, pos))->data) >= top - max_length) ||
            (*((int *)(ft_list_at(stack, pos))->data) > bottom && *((int *)(ft_list_at(stack, pos))->data) <= bottom + max_length))
            break;
        pos--;
        counter++;
    }
    return (counter + 1);
}

int    ft_set_on_b_nearest(t_list **a_stack, t_list **b_stack)
{
    int max_length;
    int top;
    int bottom;
    int bottom_up;
    int up_bottom;

    if (!a_stack || !b_stack)
        return 0;
    max_length = 4;
    top = *((int *)ft_list_at(*a_stack, ft_get_head_less_x(*a_stack))->data);
    bottom = *((int *)ft_list_at(*a_stack, ft_get_bottom_less_x(*a_stack))->data);
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

void    ft_insert_top(t_list  **a_stack, t_list **b_stack)
{
    int nb_rotation;
    int nbOp;

    nbOp = 0;
    nb_rotation = 1;

    while (*a_stack && *b_stack && *((int *)(*a_stack)->data) < *((int *)(*b_stack)->data))
    {
        nb_rotation++;
        nbOp += ft_op("ra", a_stack, b_stack, 1);
    }
    nbOp += ft_op("pa", a_stack, b_stack, 1);

    while (--nb_rotation)
    {
        while (*a_stack && *b_stack && (*((int *)(*a_stack)->data) - *((int *)(*b_stack)->data) == 1))
        {
            nbOp += ft_op("pa", a_stack, b_stack, 1);
        }
        nbOp += ft_op("rra", a_stack, b_stack, 1);
    }
}

void    ft_insert_bottom(t_list  **a_stack, t_list **b_stack)
{
    int nb_rotation;
    int nbOp;

    nbOp = 0;
    nb_rotation = 1;
    while (*((int *)ft_list_last(*a_stack)->data) > *((int *)(*b_stack)->data))
    {
        nb_rotation++;
        nbOp += ft_op("rra", a_stack, b_stack, 1);
    }
    nbOp += ft_op("pa", a_stack, b_stack, 1);
    while (nb_rotation--)
    {
        if (*a_stack && *b_stack && (*((int *)(*b_stack)->data) - *((int *)ft_list_last(*a_stack)->data) == 1))
        {
            nbOp += ft_op("pa", a_stack, b_stack, 1);
            nbOp += ft_op("ra", a_stack, b_stack, 1);
        }
        nbOp += ft_op("ra", a_stack, b_stack, 1);
    }
}

void     ft_order_stack(t_list  **a_stack, t_list **b_stack)
{
    if (ft_list_size(*a_stack) == 0)
        ft_op("pa", a_stack, b_stack, 1);
    while (ft_list_size(*b_stack) != 0)
    {
        ft_set_on_b_nearest(a_stack, b_stack);
        if (*((int *)(*b_stack)->data) < *((int *)ft_list_at(*a_stack, (ft_list_size(*a_stack) / 2))->data) || *((int *)
                (*b_stack)->data) < *((int*)(*a_stack)->data))
            ft_insert_top(a_stack, b_stack);
        else
            ft_insert_bottom(a_stack, b_stack);
    }
}

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
        {
            ft_op("pb", a_stack, b_stack, 1);
            if (ft_list_size(*b_stack) >= 2 &&
                *((int *)((*b_stack)->data)) < stack_initial_size / 2 &&
                *((int *)((*b_stack)->next->data)) < stack_initial_size / 2 &&
                *((int *)((*b_stack)->data)) < (*((int *)((*b_stack)->next->data))))
                ft_op("sb", a_stack, b_stack, 1);
            else if (ft_list_size(*b_stack) >= 2 &&
                     *((int *)((*b_stack)->data)) > stack_initial_size / 2 &&
                     *((int *)((*b_stack)->next->data)) > stack_initial_size / 2 &&
                     *((int *)((*b_stack)->data)) > (*((int *)((*b_stack)->next->data))))
                ft_op("sb", a_stack, b_stack, 1);
        }
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

void print_stacks(t_list *stack_a, t_list *stack_b, char *status)
{
    ft_printf("--------------------------------------------------------------\n\n%s\n\nA stack\n", status);
    if (stack_a) ft_list_print_int(stack_a);
    else ft_printf("NA\n");

    ft_printf("\n\nB stack\n");
    if (stack_b) ft_list_print_int(stack_b);
    else ft_printf("NA\n\n---------------------------------------------------------------\n");
    ft_printf("---------------------------------------------------------------\n");
}