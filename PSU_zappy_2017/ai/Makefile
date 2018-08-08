##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

CC		=	g++

RM		=	rm -rf

CXXFLAGS	+=	-W -Wall -Wextra -Werror -std=c++17 -g3

NAME		=	../zappy_ai

CPPFLAGS	+=	-I include/

SRC		=	src/main.cpp			\
			src/data.cpp			\
			src/player.cpp			\
			src/read_functions.cpp		\
			src/Ai.cpp			\
			src/RitualSrc/Ritual.cpp	\
			src/RitualSrc/RitualLv1.cpp	\
			src/RitualSrc/RitualLv2.cpp	\
			src/RitualSrc/RitualLv3.cpp	\
			src/RitualSrc/RitualLv4.cpp	\
			src/RitualSrc/RitualLv5.cpp	\
			src/RitualSrc/RitualLv6.cpp	\
			src/RitualSrc/RitualLv7.cpp	\

OBJ		=	$(SRC:.cpp=.o)

TMP		=	$(SRC:.cpp=.cpp~)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)
		$(RM) $(TMP)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re
