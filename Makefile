##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=	main.c	\
		init.c	\
		while_display_main.c	\
		calculations.c	\
		change_speed_or_pos.c	\
		analyse_event.c	\
		place_circles.c	\
		init2.c	\
		binary_clock.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_screensaver

GFLAGS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -L./lib/my -lmy

CC	=	gcc -Wall -Wextra -Werror -W

all:	prepare_lib $(NAME)

prepare_lib:
	make -C lib/my

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(GFLAGS) $(CFLAGS) -lm

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
