/*
** EPITECH PROJECT, 2018
** move_functions.c
** File description:
** move_functions.c
*/

#include <unistd.h>
#include <string.h>
#include "struct.h"
#include "zappy_server.h"

void update_position(t_env *e, char *cmd, int fd)
{
	int x = get_player_x(e, fd);
	int y = get_player_y(e, fd);
	
	(void)cmd;
	if (e->client[fd].orientation == 1)
		if (y == e->y)
			e->bloc = set_player_y(e, fd, SET, 0);
		else
			e->bloc = set_player_y(e, fd, ADD, 1);
	else if (e->client[fd].orientation == 2)
		if (x == e->x)
			e->bloc = set_player_x(e, fd, SET, 0);
		else
			e->bloc = set_player_x(e, fd, ADD, 1);
	else if (e->client[fd].orientation == 3)
		if (y == 0)
			e->bloc = set_player_y(e, fd, SET, e->y);
		else
			e->bloc = set_player_y(e, fd, ADD, -1);
	else
		if (x == 0)
			e->bloc = set_player_x(e, fd, SET, e->x);
		else
			e->bloc = set_player_x(e, fd, ADD, -1);
	write(fd, "ok\n", 3);
}

void update_orientation(t_env *e, char *cmd, int fd)
{
	if (strcmp("Right\n", cmd) == 0)
		if (e->client[fd].orientation == 4)
			e->client[fd].orientation = 1;
		else
			e->client[fd].orientation += 1;
	else
		if (e->client[fd].orientation == 1)
			e->client[fd].orientation = 4;
		else
			e->client[fd].orientation -= 1;
	write(fd, "ok\n", 3);
}
