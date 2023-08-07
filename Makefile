NAME = push_swap
LIBFT = 42-Libft/libft/libft.a

INCLUDE = -I./ -I./42-Libft/
CFLAGS = -Wall -Wextra -Werror

SRC_NAMES = main.c \
		others.c \
		instructions.c \
		selection_sort.c \
		small_stack_sort.c \
		sort.c 
		
		

SRCS = $(addprefix srcs/, $(SRC_NAMES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cc -g $(CFLAGS) -L 42-Libft/libft/ -lft $(OBJS) -o $(NAME)

%.o: srcs/%.c
	cc $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C 42-Libft/libft

fclean: clean
	rm -f $(NAME)
	
clean: 
	rm -f $(OBJS)
	make clean -C 42-Libft/libft

re: fclean all

.PHONY: all clean fclean re
