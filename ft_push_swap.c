#include "includes/ft_push_swap.h"
#include "includes/ft_checker.h"

int     main(int argc, char *argv[])
{
    t_list* a_stack;
    t_list* b_stack;
    int*    tmp;
    int     nb_elems;

    if (argc == 1)
        return (0);
    b_stack = 0;
    while (--argc) {
        if (!(tmp = (int *) malloc(sizeof(int))))
            return (0);
        *tmp = ft_atoi(argv[argc]);
        ft_list_push_front(&a_stack, tmp);
    }

    print_stacks(a_stack, b_stack);
    nb_elems = ft_refractor(a_stack);
    print_stacks(a_stack, b_stack);
    ft_push_a_stack_slide(&a_stack, &b_stack, nb_elems, 0);
    print_stacks(a_stack, b_stack);
    ft_push_a_stack_slide(&a_stack, &b_stack, nb_elems, 1);
    print_stacks(a_stack, b_stack);
    ft_push_a_stack_slide(&a_stack, &b_stack, nb_elems, 2);
    print_stacks(a_stack, b_stack);
    ft_push_a_stack_slide(&a_stack, &b_stack, nb_elems, 3);
    print_stacks(a_stack, b_stack);

    return (1);
}

int     ft_push_a_stack_slide(t_list **a_stack, t_list **b_stack, int nb_elems, int iteration)
{
    int     slide_size;
    int     counter;
    int     current_size;

    counter = 0;
    current_size = ft_list_size(*a_stack);
    slide_size = ft_ceil(nb_elems / 8 + iteration * (nb_elems / 8) + 1);
    while(counter < current_size)
    {
        printf("\n********\n%d, %d, %d\n*********\n", nb_elems, slide_size, current_size);
        if (*((int *)((*a_stack)->data)) <= slide_size || *((int *)((*a_stack)->data)) >= nb_elems - slide_size)
            ft_push_b(a_stack, b_stack);
        else ft_rotate(a_stack);
        counter++;
    }
    printf("\n********\n%d, %d, %d\n*********\n", nb_elems, slide_size, current_size);

    return (slide_size);
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

void print_stacks(t_list *stack_a, t_list *stack_b)
{
    printf("--------------------------------------------------------------\n\nA stack\n");
    if (stack_a) ft_list_print_int(stack_a);
    else printf("NA\n");

    printf("\n\nB stack\n");
    if (stack_b) ft_list_print_int(stack_b);
    else printf("NA\n\n---------------------------------------------------------------\n");
}