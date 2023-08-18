NAME = get_next_line
# SRCS_BONUS =
SRCS = get_next_line.c get_next_line_utils.c main.c

OBJS = $(SRCS:.c=.o)
# OBJS_BONUS = $(SRCS_BONUS:.c=.o)  # Não há definição de SRCS_BONUS

CC = gcc
# CFLAGS = -Wall -Wextra
RM = rm -rf

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(GREEN)Creating $@$(RESET)\n"
	@$(CC) -o $(NAME) $(OBJS)

%.o: %.c
	@$(CC) -c $< -o $@
	@printf "$(GREEN)Compiling $<$(RESET)\n"
	@sleep 0.1

# bonus: $(OBJS_BONUS)
# 	@printf "$(GREEN)Compiling bonus$(RESET)\n"
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS)

clean:
	@printf "$(RED)Cleaning objects$(RESET)\n"
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@printf "$(RED)Cleaning $(NAME)$(RESET)\n"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean
# bonus
