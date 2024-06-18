##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	src/my_check.c \
		src/my_engine_geometry.c \
		src/my_engine.c \
		src/my_get.c \
		src/my_put.c \
		src/my_report.c \
		src/main.c

CFLAGS	=	-Wall -Wextra

INCLUDE =	-I include -o

LIB	=	-g -lm

NAME	=	104intersection

TESTS 	= 	tests

all:	$(NAME)

$(NAME):
	make -C $(TESTS)
	gcc $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re