#include "includes/ft_push_swap.h"
#include "includes/ft_checker.h"

void    ft_insert_top(t_list  **a_stack, t_list **b_stack)
{
    int nb_rotation;

    nb_rotation = 1;

    while (*a_stack && *b_stack && *((int *)(*a_stack)->data) < *((int *)(*b_stack)->data))
    {
        nb_rotation++;
        ft_op("ra", a_stack, b_stack, 1);
    }
    ft_op("pa", a_stack, b_stack, 1);

    while (--nb_rotation)
    {
        while (*a_stack && *b_stack && (*((int *)(*a_stack)->data) - *((int *)(*b_stack)->data) == 1))
            ft_op("pa", a_stack, b_stack, 1);
        ft_op("rra", a_stack, b_stack, 1);
    }
}

void    ft_insert_bottom(t_list  **a_stack, t_list **b_stack)
{
    int nb_rotation;

    nb_rotation = 1;
    while (*((int *)ft_list_last(*a_stack)->data) > *((int *)(*b_stack)->data))
    {
        nb_rotation++;
        ft_op("rra", a_stack, b_stack, 1);
    }
    ft_op("pa", a_stack, b_stack, 1);
    while (nb_rotation--)
    {
        if (*a_stack && *b_stack && (*((int *)(*b_stack)->data) - *((int *)ft_list_last(*a_stack)->data) == 1))
        {
            ft_op("pa", a_stack, b_stack, 1);
            ft_op("ra", a_stack, b_stack, 1);
        }
        ft_op("ra", a_stack, b_stack, 1);
    }
}