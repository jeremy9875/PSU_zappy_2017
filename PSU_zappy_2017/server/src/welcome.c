/*
** EPITECH PROJECT, 2018
** welcome.c
** File description:
** welcome.c
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "define_server.h"
#include "struct.h"

element *search_team(int fd, char *team, element *teamName)
{
	element *tmp = teamName;
	while (tmp != NULL) {
		if (strncmp(team, tmp->msg, strlen(team) - 1) == 0) {
			if (tmp->fd >= 1)
				tmp->fd -= 1;
			else
				return NULL;
			dprintf(fd, "%d\n",tmp->fd);
			return tmp;
		}
		tmp = tmp->nxt;
	}
	return NULL;
}

int welcome(int fd, t_env *e)
{
	char buffer[BUF_SIZE];
	int end;

	dprintf(fd, "Welcome\n");
	end = read(fd, buffer, BUF_SIZE);
	buffer[end] = '\0';
	if ((e->name = search_team(fd, buffer, e->name)) == NULL)
		return ERROR;
	dprintf(fd, "%d %d\n", e->x, e->y);
	return OK;
}
