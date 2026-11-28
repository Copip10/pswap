NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= push_swap.c \
		  input_checker.c \
		  create_chain.c \
		  ft_split.c \
		  ft_basics_1.c \
		  ft_basics_2.c \
		  chain_functions_a.c \
		  chain_functions_b.c \
		  chain_functions_ba.c \
		  simple.c \
		  medium.c \
		  complex.c \
		  ft_bench.c \
		  ft_bench_2.c \
		  ft_free.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
