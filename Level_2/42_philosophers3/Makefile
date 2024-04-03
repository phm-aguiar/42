#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re valgrind run make_temp
HIDE = @
TEMP_PATH = temp/


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -I./$(INCDIR) -pthread 
RM		=	rm -f

# Output file name
NAME	=	philo

# Sources are all .c files
SRCDIR	=	src/
SRCS	=	src/init.c \
			src/utils.c \
			src/monitor.c \
			src/routine.c \
			src/main.c

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# Includes are all .h files
INCDIR	=	include/
INC		=	$(INCDIR)philo.h


#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	$(HIDE)mkdir -p $@

clean:
	$(HIDE)$(RM) $(OBJS)

fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(RM) -rf $(TEMP_PATH)

re: fclean all

run: all
	$(HIDE)./$(NAME) 4 400 200 200 2

make_temp:
	@mkdir -p $(TEMP_PATH)

valgrind: all make_temp 
	@valgrind -s -q  --tool=helgrind --log-file=$(TEMP_PATH)helgrind.log ./$(NAME) 4 800 200 200