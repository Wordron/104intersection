##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC    =	main.c	\
			find_lambda.c	\
			display.c	\
			cylinder.c 	\
			sphere.c	\
			cone.c	\


OBJ    =    $(SRC:.c=.o)

NAME	=	104intersection

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lm

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
