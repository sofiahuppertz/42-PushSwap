NAME = push_swap
LIBFT = TeaParty/MadHatter/libft.a
LIBFT_PATH = TeaParty/MadHatter 

INCLUDE = -I./ -I.$(LIBFT_PATH)
CFLAGS = -Wall -Wextra -Werror -g3

SRC_NAMES = Alice.c \
		CardSoldiers.c \
		CatChoice.c \
		CaterpillarListHandlers.c \
		MiniatureDoorSort.c \
		QueenOfHeartSort.c \
		WhiteRabbitHelpers.c \
		WhiteRabbitParser.c \
		WonderlandBasics.c \

SRCS = $(addprefix srcs/, $(SRC_NAMES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cc -g $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: srcs/%.c
	cc -g $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	
clean: 
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)
re: fclean all

.PHONY: all clean fclean re
