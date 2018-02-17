#include "includes/ft_push_swap.h"
#include "includes/ft_checker.h"

int     main(int argc, char *argv[])
{
    t_list* a_stack;
    t_list* b_stack;
    int*    tmp;
    int     nb_elems;
    int     nbOp;
    int     slide_size;
    //int     nb_slides;
    int     to_remove;

    nbOp = 0;
    nb_elems = 0;
    if (argc == 1)
        return (0);
    b_stack = 0;
    while (--argc) {
        if (!(tmp = (int *) malloc(sizeof(int))))
            return (0);
        *tmp = ft_atoi(argv[argc]);
        ft_list_push_front(&a_stack, tmp);
        nb_elems++;
    }

    nb_elems = ft_refractor(a_stack);

    slide_size = nb_elems / (nb_elems / 10);
    to_remove = ft_push_slides(&a_stack, &b_stack, slide_size, slide_size, nb_elems);

    nbOp += ft_order_stack(a_stack, b_stack);

    //print_stacks(a_stack, b_stack, "LAST print -- Should be ordered");
    //printf("\nPre-operations = %d, Total Operations = %d", to_remove, nbOp);
    return (1);
}

int     ft_order_stack(t_list  *a_stack, t_list *b_stack)
{
    int nb_rotation;
    int nbOp;

    nbOp = 0;
    nb_rotation = 1;
    nbOp += ft_op("pa", &a_stack, &b_stack, 1);

    while (ft_list_size(b_stack) != 0)
    {
        if (b_stack && a_stack && ((*((int *)b_stack->data) - *((int *)a_stack->data) != 1) || *((int*)ft_list_last(a_stack)->data) - *((int *)b_stack->data) != 1))
        {
            if (*((int*)ft_list_last(a_stack)->data) - *((int *)b_stack->data) >= *((int *)b_stack->data) - *((int*)a_stack->data))
            {//Insert by the top
                while (*((int *)a_stack->data) < *((int *)b_stack->data))
                {
                    nb_rotation++;
                    nbOp += ft_op("ra", &a_stack, &b_stack, 1);
                }
                nbOp += ft_op("pa", &a_stack, &b_stack, 1);
                nbOp += ft_op("rra", &a_stack, &b_stack, nb_rotation - 1);
            }
            else
            {//Insert by the bottom
                while (*((int *)ft_list_last(a_stack)->data) > *((int *)b_stack->data))
                {
                    nb_rotation++;
                    nbOp += ft_op("rra", &a_stack, &b_stack, 1);
                }
                nbOp += ft_op("pa", &a_stack, &b_stack, 1);
                nbOp += ft_op("ra", &a_stack, &b_stack, nb_rotation);
            }
        }
        else if (b_stack && a_stack && *((int *)b_stack->data) > *((int *)a_stack->data))
        {
            nbOp += ft_op("pa", &a_stack, &b_stack, 1);
            nbOp += ft_op("sa", &a_stack, &b_stack, 1);
        }
        else if (b_stack && a_stack && *((int *)b_stack->data) < *((int *)a_stack->data))
            nbOp += ft_op("pa", &a_stack, &b_stack, 1);
        nb_rotation = 1;
        //print_stacks(a_stack, b_stack, "AFTER");
        //printf("\nPre-operations = %d, Total Operations = %d", to_remove, nbOp);
    }
    return (nbOp);
}

int     ft_push_slides(t_list **a_stack, t_list **b_stack, int max, int slide_size, int nb_elems)
{
    int     counter;
    int     stack_size;

    counter = 0;
    stack_size = ft_list_size(*a_stack);
    if (stack_size == 0)
        return (counter);
    while (counter++ < stack_size)
    {
        if (*a_stack && (*((int *)((*a_stack)->data)) <= max || *((int *)((*a_stack)->data)) >= nb_elems - max))
        {
            counter += ft_op("pb", a_stack, b_stack, 1);

            if (ft_list_size(*b_stack) >= 2 &&
                *((int *)((*b_stack)->data)) < nb_elems / 2 &&
                *((int *)((*b_stack)->next->data)) < nb_elems / 2 &&
                *((int *)((*b_stack)->data)) < (*((int *)((*b_stack)->next->data))))
                counter += ft_op("sb", a_stack, b_stack, 1);
            else if (ft_list_size(*b_stack) >= 2 &&
                     *((int *)((*b_stack)->data)) > nb_elems / 2 &&
                     *((int *)((*b_stack)->next->data)) > nb_elems / 2 &&
                     *((int *)((*b_stack)->data)) > (*((int *)((*b_stack)->next->data))))
                counter += ft_op("sb", a_stack, b_stack, 1);
        }
        else
            counter += ft_op("ra", a_stack, b_stack, 1);
    }
    return (counter + ft_push_slides(a_stack, b_stack, max + slide_size, slide_size, nb_elems));
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
}