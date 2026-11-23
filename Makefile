NAME= libft.a
CC= cc

CFLAGS= -Wall -Wextra -Werror -Iincludes

SRC=	ft_bzero.c
	

OBJ= $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY :
	re fclean clean all