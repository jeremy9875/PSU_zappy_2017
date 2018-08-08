/*
** EPITECH PROJECT, 2018
** bct.c
** File description:
** bct.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

int treat_first(char *cmd)
{
	int it = 0;
	int it_buf = 0;
	char buf[10];
	
	while (cmd[it] != ' ')
		it += 1;
	it += 1;
	while (cmd[it] != ' ') {
		buf[it_buf] = cmd[it];
		it += 1;
		it_buf += 1;
	}
	buf[it] = '\0';
	return atoi(buf);
}

int treat_second(char *cmd)
{
	char buf[10];
	int it = 0;
	int it_buf = 0;
	int check = 0;

	while (check != 2) {
		if (cmd[it] == ' ')
			check += 1;
		it += 1;
	}
	it += 1;
	while (cmd[it] != '\0') {
		buf[it_buf] = cmd[it];
		it += 1;
		it_buf += 1;
	}
	buf[it] = '\0';
	return atoi(buf);
}

char *search_tile(t_env *e, int type, int x, int y)
{
	t_bloc *tmp = e->bloc;
	int nb_elem = 0;
	char *number;

	if ((number = malloc(sizeof(char) * 5)) == NULL)
		return NULL;
	while (tmp != NULL) {
		if (tmp->x == x && tmp->y == y && tmp->type == type)
			nb_elem += 1;
		tmp = tmp->nxt;
	}
	sprintf(number, "%d", nb_elem);
	return number;
}

void bct_function(t_env *e, char *cmd, int fd)
{
	if (strlen(cmd) < 7)
		return ;
	int x = treat_first(cmd);
	int y = treat_second(cmd);
	char *info;

	if ((info = malloc(sizeof(char) * BUF_SIZE)) == NULL)
		return ;
	strncat(info, cmd, strlen(cmd) - 1);
	strcat(info, " ");
	strcat(info, search_tile(e, 6, x, y));
	strcat(info, " ");
	strcat(info, search_tile(e, 0, x, y));
	strcat(info, " ");
	strcat(info, search_tile(e, 1, x, y));
	strcat(info, " ");
	strcat(info, search_tile(e, 2, x, y));
	strcat(info, " ");
	strcat(info, search_tile(e, 3, x, y));
	strcat(info, " ");
	strcat(info, search_tile(e, 4, x, y));
	strcat(info, " ");
	strcat(info, search_tile(e, 5, x, y));
	dprintf(fd, "%s\n", info);
}
