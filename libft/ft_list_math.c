#include "includes/libft.h"

t_list     *ft_list_find_min(t_list *stack)
{
    t_list *min;

    min = stack;
    stack = stack->next;
    while (stack)
    {
        if (*((int *)min->data) > *((int *)stack->data))
            min = stack;
        stack = stack->next;
    }
    return (min);
}

t_list  *ft_list_find_max(t_list *stack)
{
    t_list *max;

    max = stack;
    stack = stack->next;
    while (stack)
    {
        if (*((int *)max->data) < *((int *)stack->data))
            max = stack;
        stack = stack->next;
    }
    return (max);
}

int     ft_list_avg(t_list *stack)
{
    int nb_elem;
    int sum;

    sum = 0;
    nb_elem = 0;
    while (stack)
    {
        nb_elem++;
        sum += *((int *)stack->data);
        stack = stack->next;
    }
    return (sum / nb_elem);
}

int     ft_list_get_nb_smaller(t_list *stack, t_list *elem)
{
    int counter;

    counter = 0;
    while (stack)
    {
        if (*((int *)stack->data) < *((int *)elem->data))
            counter++;
        stack = stack->next;
    }
    return (counter);
}