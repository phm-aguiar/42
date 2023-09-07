# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 15:04:37 by phenriq2          #+#    #+#              #
#    Updated: 2023/09/07 14:01:36 by phenriq2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do seu projeto
NAME = libftprintf.a

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror

# Diretórios de inclusão
INCLUDES = -I./include -I./42_libft

# Arquivos fonte
SRCS = ft_flags_base.c ft_flags.c ft_printf.c

# Arquivos-objeto
OBJS = $(SRCS:.c=.o)

# Bibliotecas
LIBFT = 42_libft/libft.a

# Regras
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBFT)

$(LIBFT):
	make -C 42_libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C 42_libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C 42_libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

