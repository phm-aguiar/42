NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_flags_base.c ft_flags.c ft_printf.c
SRCS_BONUS = ft_flags_base_bonus.c ft_flags_bonus.c ft_printf_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

all: libft $(NAME)

$(NAME): $(OBJS)
	@printf "$(GREEN)Creating $@$(RESET)\n"
	@ar rcs $(NAME) $(OBJS)

libft:
	@make -C ./libft --no-print-directory
	@cp ./libft/libft.a $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiling $<$(RESET)\n"

bonus: libft $(OBJS_BONUS)
	@printf "$(GREEN)Compiling bonus$(RESET)\n"
	@ar rcs $(NAME) $(OBJS_BONUS)

clean:
	@make -C libft clean --no-print-directory
	@printf "$(RED)Cleaning objects$(RESET)\n"
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make -C libft fclean --no-print-directory
	@printf "$(RED)Cleaning $(NAME)$(RESET)\n"
	@$(RM) $(NAME)


re: fclean all

.PHONY: all clean re fclean libft bonus






