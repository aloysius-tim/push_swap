#include "includes/ft_checker.h"

int     main(int argc, char *argv[])
{
    t_list* a_stack;
    t_list* b_stack;
    int*    tmp;
    char*   current_instruction;

    if (argc == 1)
        return (0);
    while (--argc) {
        if (!(tmp = (int *) malloc(sizeof(int))))
            return (0);
        if (!ft_isdigit(*argv[argc]))
            exit_error();
        *tmp = ft_atoi(argv[argc]);
        ft_list_push_front(&a_stack, tmp);
    }
    if (ft_list_has_duplicates_int(a_stack))
        exit_error();
    while (get_next_line(0, &current_instruction)) {
        ft_handle_instruction(current_instruction, &a_stack, &b_stack);
    }
    if (ft_list_is_ordered_int(a_stack))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    ft_list_clear(&a_stack);
    ft_list_clear(&b_stack);
    return (1);
}

int     ft_handle_instruction(char *instruction, t_list **a_stack, t_list **b_stack)
{
    if (ft_strcmp(instruction, "sa") == 0)
        return (ft_swap(a_stack));
    else if (ft_strcmp(instruction, "sb") == 0)
        return (ft_swap(b_stack));
    else if (ft_strcmp(instruction, "ss") == 0)
        return (ft_swap(a_stack) + ft_swap(b_stack));
    else if (ft_strcmp(instruction, "pa") == 0)
        return (ft_push(a_stack, b_stack));
    else if (ft_strcmp(instruction, "pb") == 0)
        return (ft_push(b_stack, a_stack));
    else if (ft_strcmp(instruction, "ra") == 0)
        return (ft_rotate(a_stack, 1));
    else if (ft_strcmp(instruction, "rb") == 0)
        return (ft_rotate(b_stack, 1));
    else if (ft_strcmp(instruction, "rr") == 0)
        return (ft_rotate(a_stack, 1) + ft_rotate(b_stack, 1));
    else if (ft_strcmp(instruction, "rra") == 0)
        return (ft_reverse_rotate(a_stack, 1));
    else if (ft_strcmp(instruction, "rrb") == 0)
        return (ft_reverse_rotate(b_stack, 1));
    else if (ft_strcmp(instruction, "rrr") == 0)
        return (ft_reverse_rotate(a_stack, 1), ft_reverse_rotate(b_stack, 1));
    else
        exit_error();
    return (0);
}