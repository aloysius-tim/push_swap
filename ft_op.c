#include "includes/ft_checker.h"

void ft_op(char *instruction, t_list **a_stack, t_list **b_stack, int nb_op)
{
    int counter;
    int tmp;

    counter = 0;
    if (ft_strcmp(instruction, "sa") == 0)
        (ft_swap(a_stack));
    else if (ft_strcmp(instruction, "sb") == 0)
        (ft_swap(b_stack));
    else if (ft_strcmp(instruction, "ss") == 0)
        tmp = (ft_swap(a_stack) + ft_swap(b_stack));
    else if (ft_strcmp(instruction, "pa") == 0)
        (ft_push(a_stack, b_stack));
    else if (ft_strcmp(instruction, "pb") == 0)
        (ft_push(b_stack, a_stack));
    else if (ft_strcmp(instruction, "ra") == 0)
        (ft_rotate(a_stack, nb_op));
    else if (ft_strcmp(instruction, "rb") == 0)
        (ft_rotate(b_stack, nb_op));
    else if (ft_strcmp(instruction, "rr") == 0)
        tmp = (ft_rotate(a_stack, nb_op) + ft_rotate(b_stack, nb_op));
    else if (ft_strcmp(instruction, "rra") == 0)
        (ft_reverse_rotate(a_stack, nb_op));
    else if (ft_strcmp(instruction, "rrb") == 0)
        (ft_reverse_rotate(b_stack, nb_op));
    else if (ft_strcmp(instruction, "rrr") == 0)
        tmp = (ft_reverse_rotate(a_stack, nb_op), ft_reverse_rotate(b_stack, nb_op));
    else
        exit_error();
    while (counter++ < nb_op)
        ft_printf("%s\n", instruction);
}

int ft_swap(t_list** stack)
{
    int tmp;
    int size;

    size = ft_list_size(*stack);
    if (size <= 1)
        return (1);
    tmp = *((int *)ft_list_at(*stack, 0)->data);
    *((int *)ft_list_at(*stack, 0)->data) = *((int*)ft_list_at(*stack, 1)->data);
    *((int*)ft_list_at(*stack, 1)->data) = tmp;
    return (1);
}

int ft_push(t_list** stack_a, t_list** stack_b)
{
    if ((ft_list_size(*stack_b)) == 0)
        return (1);
    ft_list_push_front(stack_a, ft_list_pop(stack_b));
    return (1);
}

int ft_rotate(t_list** stack, int nb)
{
    void *tmp;
    int counter;

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

int ft_reverse_rotate(t_list** stack, int nb)
{
    void *tmp;
    int counter;

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