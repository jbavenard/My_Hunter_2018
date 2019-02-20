##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	./src/main.c \
		./src/textures.c\
		./src/sprites.c \
		./src/dynamics.c\


LIB	=	./lib/my_putstr.c \
		./lib/my_putchar.c \
		./lib/my_put_nbr.c \
		./lib/my_strlen.c

OBJ	=	$(SRC:.c=.o)

OBJLIB	=	$(LIB:.c=.o)

NAME	=	my_hunter

NAMELIB = libmy.a

GFLAGS	=	-Wextra -I include -

all : $(NAMELIB) $(NAME) clean

$(NAME):
	gcc -L./lib $(SRC) -lmy -lcsfml-graphics -lcsfml-system -o $(NAME)

$(NAMELIB):
	gcc -c $(LIB)
	mv *.o ./lib
	ar rc $(NAMELIB) $(OBJLIB)
	mv $(NAMELIB) ./lib/libmy.a
	rm -f ./lib/*.o

clean:
	rm -f $(OBJ)
	rm -f $(OBJLIB)

fclean: clean
	rm -f $(NAME)
	rm -f ./lib/libmy.a

re: fclean all
