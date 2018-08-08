##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

all			:	zappy_ai zappy_server

zappy_ai		:
				make -C ai/

zappy_server		:
				make -C server/

clean			:
				make -C ai/ clean
				make -C server/ clean

fclean			:	clean
				make -C ai/ fclean
				make -C server/ fclean

re			:	fclean all

.PHONY			:	all clean fclean re
