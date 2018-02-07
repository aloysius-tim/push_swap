#include "includes/ft_checker.h"

int     main(int argc, char *argv[])
{
    t_list* a_stack;
    t_list* b_stack;
    (void)b_stack;
    int*    tmp;
    char*   current_instruction;

    while (--argc)
    {
        if (!(tmp = (int*)malloc(sizeof(int))))
            return (0);
        *tmp = ft_atoi(argv[argc]);
        ft_list_push_front(&a_stack, tmp);
    }
    //ft_list_print_int(a_stack);

    //while (ft_list)
    get_next_line(0, &current_instruction);
    //ft_swap(&a_stack);

    printf("Is ordered = %d", ft_list_is_ordered_int(a_stack));

    return (1);
}