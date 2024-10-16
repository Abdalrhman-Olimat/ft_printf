NAME = libftprintf.a
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_print_unsigned.c ft_print_xX.c ft_print_ptr.c

all: $(NAME)

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
