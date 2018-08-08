##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

CC		=	g++

RM		=	rm -rf

#CXXFLAGS	+=	-W -Wall -Wextra -Werror

NAME		=	zappy_graphic

CPPFLAGS	+= 	-I ./include/

SRC		=	src/CreateWindow.cpp 	\
			src/ZappyWin.cpp	\
			src/Data.cpp		\
			src/Connect.cpp		\
			src/map.cpp		\
			src/checkstr.cpp	\

OBJ		=	$(SRC:.cpp=.o)

TMP		=	$(SRC:.cpp=.cpp~)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) -lsfml-window -lsfml-graphics -lsfml-system $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(TMP)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
