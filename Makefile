
NAME	:=	sudoku_resolv

SRC	:=	main.c \
		parser.c \
		init.c \
		get_next_line.c \
		display.c \
		resolv.c \
		check.c

CC	:=	cc

INC_DIR	:=	include

OBJ	:=	$(SRC:.c=.o)

CFLAGS  :=	-Wall -Wextra -W -pedantic -ansi 
CFLAGS	+=	-I$(INC_DIR)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:		fclean all
