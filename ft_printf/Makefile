NAME = libftprintf.a

SRC = ft_printf.c

PARSER = parser/ft_parse_flags.c \
      parser/ft_parser.c \
      parser/ft_flag_optm.c

UTILS = utils/ft_size.c \
      utils/ft_putnbr.c

PRINT = print/ft_print.c \
      print/ft_print_char.c \
      print/ft_print_complete.c \
      print/ft_print_hexa.c \
      print/ft_print_int.c \
      print/ft_print_octal.c \
      print/ft_print_other.c \
      print/ft_print_unsigned.c \
      print/ft_print_wchar.c

FLAGS		=   -Wall -Werror -Wextra

HEADERS		=	include/ft_printf.h
LIB 		=	libft/libft.a

SRCS = $(SRC) $(PARSER) $(UTILS) $(PRINT)
OBJS		=	$(SRCS:.c=.o)
DEP			=	$(LIB) $(HEADER) Makefile

TEST		=   main.c \

all 		:	$(NAME)

test		:	$(NAME) main.o
				gcc -Ofast $(FLAGS) $(NAME) $(TEST)

$(NAME)		:	$(OBJS) $(DEP)
				cp $(LIB) $(NAME)
				ar rcs $(NAME) $(OBJS)

%.o 		:	%.c
				gcc -Ofast $(FLAGS) -c $< -o $@

$(LIB)		:
				make -C libft/

clean		:
				rm -rf $(OBJS) main.o
				make clean -C libft/

fclean		:	clean
				rm -f $(NAME)
				make fclean -C libft/

re			:	fclean
				make all