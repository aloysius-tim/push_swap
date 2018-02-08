#include "includes/ft_checker.h"

int     main(int argc, char *argv[])
{
    t_list* a_stack;
    t_list* b_stack;
    (void)b_stack;
    int*    tmp;
    char*   current_instruction;

    while (--argc) {
        if (!(tmp = (int *) malloc(sizeof(int))))
            return (0);
        *tmp = ft_atoi(argv[argc]);
        ft_list_push_front(&a_stack, tmp);
    }

    //printf("Is ordered %d", ft_list_is_ordered_int(a_stack));
    while (!ft_list_is_ordered_int(a_stack) || ft_list_size(b_stack) != 0) {
        get_next_line(0, &current_instruction);
        ft_handle_instruction(current_instruction, &a_stack, &b_stack);
    }

    printf("--------------------------------------------------------------\n\nA stack\n");
    ft_list_print_int(a_stack);
    printf("\n\nB stack\n---------------------------------------------------------------");
    ft_list_print_int(b_stack);

    return (1);
}

int     ft_handle_instruction(char *instruction, t_list **a_stack, t_list **b_stack)
{
    if (ft_strcmp(instruction, "sa") == 0)
        return (ft_swap(a_stack));
    else if (ft_strcmp(instruction, "sb") == 0)
        return (ft_swap(b_stack));
    else if (ft_strcmp(instruction, "ss") == 0)
        return (ft_swap_both(a_stack, b_stack));
    else if (ft_strcmp(instruction, "pa") == 0)
        return (ft_push_a(a_stack, b_stack));
    else if (ft_strcmp(instruction, "pb") == 0)
        return (ft_push_b(a_stack, b_stack));
    else if (ft_strcmp(instruction, "ra") == 0)
        return (ft_rotate(a_stack));
    else if (ft_strcmp(instruction, "rb") == 0)
        return (ft_rotate(b_stack));
    else if (ft_strcmp(instruction, "rr") == 0)
        return (ft_rotate_both(a_stack, b_stack));
    else if (ft_strcmp(instruction, "rra") == 0)
        return (ft_reverse_rotate(a_stack));
    else if (ft_strcmp(instruction, "rrb") == 0)
        return (ft_reverse_rotate(b_stack));
    else if (ft_strcmp(instruction, "rrr") == 0)
        return (ft_reverse_rotate_both(a_stack, b_stack));
    else if (ft_strcmp(instruction, "print") == 0)
    {
        printf("\n\nA stack\n");
        ft_list_print_int(*a_stack);
        printf("\n\nB stack\n");
        ft_list_print_int(*b_stack);
        return (1);
    }
    else
        return (0);
}