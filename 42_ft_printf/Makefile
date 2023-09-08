NAME = libftprintf.a
TEST = ft_printf.out
SRCS = ft_flags_base.c ft_flags.c ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -c -Wall -Werror -Wextra $(SRCS)
	@ar rc $(NAME) *.o libft/*.o

test: all
	@gcc -g $(SRCS) main.c -o $(TEST) -L. -lftprintf

clean:
	@rm -f *.o
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST)
	@make -C libft fclean

re: fclean all
