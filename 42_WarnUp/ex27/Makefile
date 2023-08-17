# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 17:57:45 by phenriq2          #+#    #+#              #
#    Updated: 2023/07/17 17:57:46 by phenriq2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
HEADER_DIR = ./includes
SRCS = \
		./srcs/ft_display_file.c \
		./srcs/ft_putchar.c \
		./srcs/arg_test.c 
OBJS = \
		ft_display_file.o \
		ft_putchar.o \
		arg_test.o 

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) $(OBJS) -o $(NAME)

%.o: ./srcs/%.c 
		$(CC) $(CFLAGS) -I$(HEADER_DIR) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean
