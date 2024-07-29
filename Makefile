CC = cc 
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
NAME = gnl.a
SRCS = get_next_line_utils.c get_next_line.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef BONUS
	OBJS = $(BONUS_OBJS)
endif

all: $(NAME)

bonus:
	make BONUS=TRUE

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
<<<<<<< HEAD
	rm -f $(OBJS) $(BONUS_OBJS)

=======
	rm -f $(OBJS)
	
>>>>>>> 234c7ad569d2f0202816b3c360466af2e397c323
fclean: clean
	rm -f $(NAME)

re:	fclean all

<<<<<<< HEAD
.PHONY: all clean fclean re bonus
=======
.PHONY: all clean fclean re
>>>>>>> 234c7ad569d2f0202816b3c360466af2e397c323
