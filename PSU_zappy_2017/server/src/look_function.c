/*
** EPITECH PROJECT, 2018
** look_function.c
** File description:
** look_function.c
*/

#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "zappy_server.h"

const char bloc[8][10] =
{
	{"linemate"},
	{"deraumere"},
	{"sibur"},
	{"mendiane"},
	{"phiras"},
	{"thystane"},
	{"food"},
	{"player"},
};

int treat_y(t_env *e, int y)
{
	y += 1;
	if (y > e->y)
		y = 0;
	return y;	
}

char *search_bloc(t_env *e, int x, int y)
{
	t_bloc *tmp = e->bloc;
	bool ressources = false;
	char *content;

	if ((content = malloc(sizeof(char) * 1000)) == NULL)
		return NULL;
	while (tmp != NULL) {
		if ((tmp->x == x) && (tmp->y == y)) {
			if (ressources)
				content = strcat(content, " ");
			content = strcat(content, bloc[tmp->type]);
			ressources = true;
		}
		tmp = tmp->nxt;
	}
	return content;
}

char *search_loop(t_env *e, int x, int y, int lvl)
{
	char *content;
	int it = 0;

	if ((content = malloc(sizeof(char) * 1000)) == NULL)
		return NULL;
	if (lvl > 0) {
		x -= lvl;
		if (x < 0)
			x = e->x;
	}
	while (it < (1 + (2 * lvl))) {
		content = strcat(content, search_bloc(e, x, y));
		content = strcat(content, ",");
		x += 1;
		if (x > e->x)
			x = 0;
		it += 1;
	}
	return content;
}

void look(t_env *e, char *cmd, int fd)
{
	int x = get_player_x(e, fd);
	int y = get_player_y(e, fd);
	char *buffer;

	(void)cmd;
	if ((buffer = malloc(sizeof(char) * 1000)) == NULL)
		return ;
	buffer = strcat(buffer, "[");
	for (int it = 0; it <= e->client[fd].lvl; it++) {
		buffer = strcat(buffer, search_loop(e, x, y, it));
		if (it == e->client[fd].lvl)
			buffer = strcat(buffer, "\b");
		y = treat_y(e, y);
	}
	buffer = strcat(buffer, "]");
	dprintf(fd, "%s\n", buffer);
	free(buffer);
}

