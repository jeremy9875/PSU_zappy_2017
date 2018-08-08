/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** error.c
*/

#include "zappy_server.h"
#include "define_server.h"

int check_alpha(char *str)
{
	int it = 0;

	while (str[it] != '\0') {
		if (str[it] < '0' || str[it] > '9')
			return ERROR;
		it += 1;
	}
	return OK;
}

int check_struct(t_env *e)
{
	if (e->port == -1 ||
	    e->x == -1 ||
	    e->y == -1 ||
	    e->name == NULL ||
	    e->nbClient == -1)
		return ERROR;
	if (e->freq == -1)
		e->freq = 100;
	return OK;
}
