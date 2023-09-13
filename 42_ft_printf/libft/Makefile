NAME = libft.a

SRCS = ft_atoi.c ft_isprint.c ft_lstiter_bonus.c ft_memmove.c ft_putnbr_base.c ft_strdup.c ft_strnew.c ft_bzero.c ft_itoa_base.c \
				ft_lstlast_bonus.c ft_memset.c ft_putnbr.c ft_striteri.c ft_strnstr.c ft_calloc.c ft_itoa.c ft_lstmap_bonus.c ft_nbrlen_base.c \
				ft_putnbr_fd.c ft_strjoin.c ft_strrchr.c ft_isalnum.c ft_itoa_unsigned.c ft_lstnew_bonus.c \
				ft_nbrlen.c ft_putptr.c ft_strlcat.c ft_strrev.c ft_isalpha.c ft_lstadd_back_bonus.c \
				ft_lstsize_bonus.c ft_putchar.c ft_putstr.c ft_strlcpy.c ft_strtrim.c ft_isascii.c \
				ft_lstadd_front_bonus.c ft_memchr.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_substr.c ft_isdigit.c ft_lstclear_bonus.c ft_memcmp.c ft_putendl.c ft_split.c ft_strmapi.c ft_tolower.c ft_isnonzero_digit.c ft_lstdelone_bonus.c\
				ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strncmp.c ft_toupper.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0
RM = rm -rf

GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;35m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(CYAN)Creating $@$(RESET)\n\n"
	@ar rcs $(NAME) $?

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiling $<$(RESET)\n"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@printf "$(RED)Cleaning $(NAME)$(RESET)\n"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean bonus
