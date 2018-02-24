#include "includes/ft_push_swap.h"
#include "includes/ft_checker.h"

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