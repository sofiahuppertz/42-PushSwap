NAME = push_swap
LIBFT = 42-Libft/libft/libft.a

INCLUDE = -I./ -I./42-Libft/libft/
CFLAGS = -Wall -Wextra -Werror

SRC_NAMES = main.c \
		instructions.c \
		median_sort.c \
		median_sort_helpers.c \
		parsing.c \
		small_stack_sort.c \
		sort.c \

SRCS = $(addprefix srcs/, $(SRC_NAMES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cc -g $(CFLAGS) $(OBJS) -L42-Libft/libft -lft -o $(NAME)

%.o: srcs/%.c
	cc -g $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C 42-Libft/libft

fclean: clean
	rm -f $(NAME)
	
clean: 
	rm -f $(OBJS)
	make clean -C 42-Libft/libft

re: fclean all

.PHONY: all clean fclean re
