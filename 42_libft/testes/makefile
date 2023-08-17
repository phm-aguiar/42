# Makefile para criar o executável de testes

CC = cc
CFLAGS = -Wall -Wextra
LIBS = -L../libft -lft
INCLUDES = -I./

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXECUTABLE = test_executable

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re


