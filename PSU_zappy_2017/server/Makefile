##
## EPITECH PROJECT, 2018
## zappy_server
## File description:
## Makefile
##

NAME			=	../zappy_server

SRCS			=	src/main.c			\
				src/client_function.c		\
				src/server_function.c		\
				src/treatement.c		\
				src/list.c			\
				src/init.c			\
				src/error.c			\
				src/set_params.c		\
				src/parser.c			\
				src/move_functions.c		\
				src/inventory_functions.c	\
				src/bloc_utils.c		\
				src/look_function.c		\
				src/take_obj_function.c		\
				src/set_obj_function.c		\
				src/welcome.c			\
				src/graphic/msz.c		\
				src/graphic/bct.c		\
				src/graphic/mct.c		\

OBJS			=	$(SRCS:.c=.o)

TMP			=	$(SRCS:.c=.c~)

CC			=	gcc

CFLAGS			=	-W -Wall -Wextra -Werror

CFLAGS			+=	-I ./include/

RM			=	rm -rf

all			:	$(NAME)

$(NAME)			:	$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

clean			:
				$(RM) $(OBJS)
				$(RM) $(TMP)

fclean			:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY			:	all clean fclean re
