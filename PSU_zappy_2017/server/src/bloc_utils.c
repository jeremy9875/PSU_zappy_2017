/*
** EPITECH PROJECT, 2018
** bloc_utils.c
** File description:
** bloc_utils.c
*/

#include <stdlib.h>
#include "struct.h"
#include "define_server.h"

int get_player_x(t_env *e, int fd)
{
	t_bloc *it = e->bloc;

	if (!e->bloc)
		return 0;
	while (it != NULL) {
		if (it->fd == fd)
			return it->x;
		it = it->nxt;
	}
	return 0;
}

int get_player_y(t_env *e, int fd)
{
	t_bloc *it = e->bloc;

	if (!e->bloc)
		return 0;
	while (it != NULL) {
		if (it->fd == fd)
			return it->y;
		it = it->nxt;
	}
	return 0;
}

t_bloc *set_player_x(t_env *e, int fd, int type, int val)
{
	t_bloc *new = e->bloc;
	
	while (new->nxt != NULL) {
		if (new->fd == fd) {
			if (type == ADD)
				new->x += val;
			else
				new->x = val;
			return new;
		}			
		new = new->nxt;
	}
	return new;
}

t_bloc *set_player_y(t_env *e, int fd, int type, int val)
{
	t_bloc *new = e->bloc;
	
	while (new->nxt != NULL) {
		if (new->fd == fd) {
			if (type == ADD)
				new->y += val;
			else
				new->y = val;
			return new;
		}			
		new = new->nxt;
	}
	return new;
}
