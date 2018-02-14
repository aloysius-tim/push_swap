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
    int     count;
    int     nb_rotation;
    int     nb_slides;
    int     to_remove;

    nb_rotation = 1;
    count = 0;
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

    if (nb_elems <= 5)
        nb_slides = 1;
    else if (nb_elems <= 10)
        nb_slides = 2;
    else if (nb_elems <= 25)
        nb_slides = 8;
    else if (nb_elems <= 50)
        nb_slides = 16;
    else if (nb_elems <= 100)
        nb_slides = 32;
    else if (nb_elems <= 250)
        nb_slides = 64;
    else
        nb_slides = 128;

    slide_size = ft_ceil(nb_elems / nb_slides + 0 * (nb_elems / nb_slides)) + 1;
    print_stacks(a_stack, b_stack, "Before refractor");
    nb_elems = ft_refractor(a_stack);
    print_stacks(a_stack, b_stack, "After refractor");

    while (ft_list_size(a_stack) != 0)
    {
        nbOp += ft_push_a_stack_slide(&a_stack, &b_stack, nb_elems, slide_size * (count + 1));
        print_stacks(a_stack, b_stack, "Iteration");
        count++;
    }
    to_remove = nbOp;

    printf("\nNb Operations = %d\n", nbOp);
    printf("\n\nTime for fucking operations\n\n");
    ft_push_a(&a_stack, &b_stack);

    while (ft_list_size(b_stack) != 0)
    {
        print_stacks(a_stack, b_stack, "BEFORE");
        if (*((int *)b_stack->data) > *((int *)a_stack->data))
        {
            while (*((int *)ft_list_last(a_stack)->data) > *((int *)b_stack->data))
            {
                nb_rotation++;
                nbOp += ft_reverse_rotate(&a_stack, 1);
            }
            nbOp += ft_push_a(&a_stack, &b_stack);
            nbOp += ft_rotate(&a_stack, nb_rotation);
        }
        if (*((int *)b_stack->data) < *((int *)a_stack->data))
        {
            nbOp += ft_push_a(&a_stack, &b_stack);
        }
        nb_rotation = 1;
        print_stacks(a_stack, b_stack, "AFTER");
        printf("\nPre-operations = %d, Total Operations = %d", to_remove, nbOp);
    }

    print_stacks(a_stack, b_stack, "LAST print -- Should be ordered");

    printf("\nPre-operations = %d, Total Operations = %d", to_remove, nbOp);
    return (1);
}

int     ft_push_a_stack_slide(t_list **a_stack, t_list **b_stack, int nb_elems, int slide_size)
{
    int     counter;
    int     current_size;
    int     nbOp;

    nbOp = 0;
    counter = 0;
    current_size = ft_list_size(*a_stack);
    printf("\n%d - %d\n", slide_size, nb_elems);
    while(counter < current_size)
    {
        if (*((int *)((*a_stack)->data)) <= slide_size || *((int *)((*a_stack)->data)) > nb_elems - slide_size)
            ft_push_b(a_stack, b_stack);
        else ft_rotate(a_stack, 1);
        nbOp++;
        counter++;
    }
    return (nbOp);
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
    printf("--------------------------------------------------------------\n\n%s\n\nA stack\n", status);
    if (stack_a) ft_list_print_int(stack_a);
    else printf("NA\n");

    printf("\n\nB stack\n");
    if (stack_b) ft_list_print_int(stack_b);
    else printf("NA\n\n---------------------------------------------------------------\n");
}