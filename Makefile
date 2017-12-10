##
## EPITECH PROJECT, 2017
## my_hunter
## File description:
## Makefile
##

SRC_DIR=	src

SRC=		$(SRC_DIR)/my_hunter.c	\
		$(SRC_DIR)/init.c	\
		$(SRC_DIR)/events.c	\
		$(SRC_DIR)/display.c

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-W -Wall -fno-builtin -g

CPPFLAGS =	-I include

LFLAGS=		-l c_graph_prog -L lib/my/ -l my

NAME=		my_hunter

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/src/
		gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
		make clean -C lib/src/
		rm -f $(OBJ)

fclean: 	clean
		make fclean -C lib/src/
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
