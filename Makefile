NAME = checker

CHECKER = ft_checker.c \
            ft_op.c
PUSH_SWAP =

FLAGS		=   -Wall -Werror -Wextra

HEADERS		=	includes/ft_checker.h
LIB 		=	libft/libft.a

SRCS        =   $(CHECKER) $(PUSH_SWAP)
OBJS		=	$(SRCS:.c=.o)
DEP			=	$(LIB) $(HEADERS) Makefile

TEST		=   main.c \

all 		:	$(NAME)

test		:	$(NAME) main.o
				gcc $(FLAGS) $(NAME) $(TEST)

$(NAME)		:	$(OBJS) $(DEP)
				gcc $(FLAGS) $(SRCS) -o $(NAME) -Llibft -lft

%.o 		:	%.c
				gcc $(FLAGS) -c $< -o $@

$(LIB)		:
				make -C libft/

clean		:
				rm -rf $(OBJS)
				make clean -C libft/

fclean		:	clean
				rm -f $(NAME)
				make fclean -C libft/

re			:	fclean
				make all