##
## EPITECH PROJECT, 2017
## my_hunter
## File description:
## Makefile
##

SRC_DIR=	.

SRC=		$(SRC_DIR)/my_hunter.c	\
		$(SRC_DIR)/tools.c

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-W -Wall -fno-builtin

CPPFLAGS =	-I include

LFLAGS=		-l c_graph_prog

NAME=		my_hunter

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
