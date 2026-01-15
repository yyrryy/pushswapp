CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC= main.c input_check.c input_check_utils.c initialization.c stack.c swap.c push.c rotate.c reverse_rotate.c sortthree.c sort.c position.c cost.c choose_the_action.c utils.c unwanted.c radix.c ft_split.c

BONUS_SRC= checker_bonus.c initialization.c utils.c stack.c swap.c push.c rotate.c reverse_rotate.c input_check_utils.c input_check.c get_next_line_bonus.c

OBJS    = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o checker

%.o: %.c push_swap.h checker.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f checker
	rm -f $(NAME)

re: fclean all

test500: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	
test100: $(NAME)
	$(eval ARG = $(shell shuf -i 100-5000 -n 100))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	
				
test1000: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re