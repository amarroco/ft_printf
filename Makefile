NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_printf_prints.c
OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	ar crs $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re bonus clean