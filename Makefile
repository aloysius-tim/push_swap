NAME_CHECKER = checker
NAME_PUSH    = push_swap
NAME         = $(NAME_CHECKER) $(NAME_PUSH)

CHECKER     = ft_checker.c \
                $(BOTH)
PUSH_SWAP   = ft_push_swap.c \
                ft_utils.c \
                $(BOTH)
BOTH        = ft_op.c \

FLAGS		=   -Wall -Werror -Wextra -fsanitize=undefined

HEADERS		=	includes/ft_checker.h \
                includes/ft_push_swap.h
LIB 		=	libft/libft.a
PRINTF      =   ft_printf/libftprintf.a

SRCS        =   $(CHECKER) $(PUSH_SWAP)
OBJS		=	$(SRCS:.c=.o)
DEP			=	$(LIB) $(HEADERS) Makefile

TEST		=   main.c \

all 		:	$(NAME_CHECKER) $(NAME_PUSH)

test		:	$(NAME) main.o
				gcc $(FLAGS) $(NAME) $(TEST)

$(NAME_CHECKER)		:	$(CHECKER:.c=.o) $(DEP)
				        gcc $(FLAGS) $(CHECKER) -o $(NAME_CHECKER) -Llibft -lft -Lft_printf ./ft_printf/libftprintf.a

$(NAME_PUSH)		:	$(PUSH_SWAP:.c=.o) $(DEP)
				        gcc $(FLAGS) $(PUSH_SWAP) -o $(NAME_PUSH) -Llibft -lft -Lft_printf ./ft_printf/libftprintf.a

%.o 		:	%.c
				gcc $(FLAGS) -c $< -o $@

$(LIB)		:
				make -C libft/

lib 		:
				make -C libft/

$(PRINTF)	:
				make -C ft_printf/

printf 		:
				make -C ft_printf/

clean		:
				rm -rf $(OBJS)
				make clean -C libft/

fclean		:	clean
				rm -f $(NAME)
				make fclean -C libft/

re			:	fclean
				make all