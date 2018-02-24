#include "includes/ft_push_swap.h"
#include "includes/ft_checker.h"

int     main(int argc, char *argv[])
{
    t_list  *a_stack;
    t_list  *b_stack;
    int     *tmp;
    int     nb_elems;
    int     nb_slides;

    nb_elems = 0;
    if (argc == 1)
        return (0);
    while (--argc && ++nb_elems) {
        if (!(tmp = (int *) malloc(sizeof(int))))
            return (0);
        if (!ft_isdigit(*argv[argc]))
            exit_error();
        *tmp = ft_atoi(argv[argc]);
        ft_list_push_front(&a_stack, tmp);
    }
    if (ft_list_has_duplicates_int(a_stack))
        exit_error();
    if (nb_elems == 2 && ft_list_is_reverse_ordered_int(a_stack))
        ft_op("sa", &a_stack, &b_stack, 1);
    if (nb_elems == 1 || ft_list_is_ordered_int(a_stack))
        return (1);
    nb_elems = ft_refractor(a_stack);
    nb_slides = ((nb_elems <= 10) ? 1 : ft_ceil(8 + (nb_elems / 200) * 2));
    (nb_slides != 1) ? ft_push_slides(&a_stack, &b_stack, nb_elems / nb_slides, 1, nb_elems, nb_slides / 4,
                                      nb_slides / 4 + 1) : ft_push_all(&a_stack, &b_stack, nb_elems);
    ft_order_stack(&a_stack, &b_stack);
    ft_list_clear(&a_stack);
    ft_list_clear(&b_stack);
    return (1);
}