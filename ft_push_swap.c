#include "includes/ft_push_swap.h"

int     main(int argc, char *argv[])
{
    t_list* a_stack;
    //t_list* b_stack;
    int*    tmp;

    if (argc == 1)
        return (0);
    while (--argc) {
        if (!(tmp = (int *) malloc(sizeof(int))))
            return (0);
        *tmp = ft_atoi(argv[argc]);
        ft_list_push_front(&a_stack, tmp);
    }

    printf("--------------------------------------------------------------\n\nA stack\n");
    ft_list_print_int(a_stack);
    printf("\n\nB stack\n---------------------------------------------------------------");
    //ft_list_print_int(b_stack);

    printf("\nMin = %d\n", *((int *)ft_list_find_min(a_stack)->data));

    ft_refractor(a_stack);

    printf("--------------------------------------------------------------\n\nA stack\n");
    ft_list_print_int(a_stack);
    printf("\n\nB stack\n---------------------------------------------------------------");
    //ft_list_print_int(b_stack);

    return (1);
}

void    ft_refractor(t_list *stack)
{
    t_list  *head;

    head = stack;
    while (stack)
    {
        *((int *)stack->data) = ft_list_get_nb_smaller(head, stack);
        stack = stack->next;
    }
}