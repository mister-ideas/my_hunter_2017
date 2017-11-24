##
## EPITECH PROJECT, 2017
## my_hunter
## File description:
## Makefile
##

SRC_DIR=	.

SRC=		$(SRC_DIR)/my_hunter.c

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-W -Wall -fno-builtin

LFLAGS=		-l c_graph_prog

NAME=		push_swap

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/src
		gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
		rm -f $(OBJ)
		make clean -C lib/src

fclean: 	clean
		rm -f $(NAME)
		make fclean -C lib/src

re:		fclean all

.PHONY:		all clean fclean re
