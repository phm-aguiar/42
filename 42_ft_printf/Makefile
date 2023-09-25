NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_flags_base.c ft_flags.c ft_printf.c ft_tratament_flags.c
OBJS = $(SRCS:%.c=%.o)

GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;35m
RESET = \033[0m

all: libft $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(CYAN)Creating $@$(RESET)\n"
	@ar rcs $(NAME) $?

libft:
	@make -C ./libft --no-print-directory
	@cp ./libft/libft.a $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiling $<$(RESET)\n"


clean:
	@make -C libft clean --no-print-directory
	@printf "$(RED)Cleaning objects$(RESET)\n"
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make -C libft fclean --no-print-directory
	@printf "$(RED)Cleaning $(NAME)$(RESET)\n"
	@$(RM) $(NAME)
	@$(RM) run


re: fclean all

main:
	@$(CC) $(CFLAGS) main.c -L . -lftprintf -o run
	./run

.PHONY: all clean re fclean libft main
