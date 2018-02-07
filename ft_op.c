#include "includes/ft_checker.h"

int ft_swap(t_list** stack)
{
    int tmp;
    int size;

    size = ft_list_size(*stack);
    if (size <= 1)
        return (0);
    tmp = *((int *)ft_list_at(*stack, 0)->data);
    *((int *)ft_list_at(*stack, 0)->data) = *((int*)ft_list_at(*stack, 1)->data);
    *((int*)ft_list_at(*stack, 1)->data) = tmp;
    return (1);
}

int ft_swap_both(t_list** stack_a, t_list** stack_b)
{
    return (ft_swap(stack_a) && ft_swap(stack_b));
}

int ft_push_a(t_list** stack_a, t_list** stack_b)
{
    int size;

    if ((size = ft_list_size(*stack_b)) == 0)
        return (0);
    ft_list_push_front(stack_a, ft_list_pop(stack_b));
    return (1);
}

int ft_push_b(t_list** stack_a, t_list** stack_b)
{
    return (ft_push_a(stack_b, stack_a));
}

int ft_rotate(t_list** stack)
{
    void *tmp;

    if (!stack || !(*stack) || ft_list_size(*stack) < 1)
        return (0);
    tmp = ft_list_pop(stack);
    ft_list_push_back(stack, tmp);
    return (1);
}

int ft_rotate_both(t_list** stack_a, t_list** stack_b)
{
    return (ft_rotate(stack_a) && ft_rotate(stack_b));
}

int ft_reverse_rotate(t_list** stack)
{
    void *tmp;

    if (!stack || !(*stack) || ft_list_size(*stack) < 1)
        return (0);
    tmp = ft_list_pop_last(stack);
    ft_list_push_front(stack, tmp);
    return (1);
}

int ft_reverse_rotate_both(t_list** stack_a, t_list** stack_b)
{
    return (ft_reverse_rotate(stack_a), ft_reverse_rotate(stack_b));
}