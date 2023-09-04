NAME = libft.a
SRCS_BONUS = \
		ft_lstdelone_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstnew_bonus.c

SRCS = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_isascii.c ft_strlen.c \
		ft_memset.c ft_tolower.c ft_toupper.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memcmp.c \
		ft_memchr.c ft_atoi.c ft_strncmp.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
		ft_calloc.c ft_strdup.c ft_split.c ft_substr.c ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
		ft_putstr_fd.c ft_itoa.c ft_strtrim.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_strlcpy.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(GREEN)Creating $@$(RESET)\n"
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiling $<$(RESET)\n"
	@sleep 0.1

bonus: $(OBJS_BONUS)
	@printf "$(GREEN)Compiling bonus$(RESET)\n"
	@ar rcs $(NAME) $(OBJS_BONUS)

clean:
	@printf "$(RED)Cleaning objects$(RESET)\n"
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@printf "$(RED)Cleaning $(NAME)$(RESET)\n"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean bonus
