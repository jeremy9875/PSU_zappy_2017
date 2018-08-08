/*
** EPITECH PROJECT, 2018
** set_params.c
** File description:
** set_params.c
*/

#include "zappy_server.h"
#include "define_server.h"

int set_port(int pos, char **src, t_env *e, int ac)
{
	if (pos + 1 >= ac)
		return ERROR;
	e->port = atoi(src[pos + 1]);
	if (e->port < PORT_MIN ||
	    check_alpha(src[pos + 1]) == ERROR)
		return ERROR;
	return OK;
}

int set_width_height(int pos, char **src, t_env *e, int ac)
{
	if (pos + 1 >= ac || check_alpha(src[pos + 1]) == ERROR)
		return ERROR;
	if (strcmp(src[pos], "-x") == 0) {
		e->x = atoi(src[pos + 1]);
		if (e->x < 1)
			return ERROR;
	} else {
		e->y = atoi(src[pos + 1]);
		if (e->y < 1)
			return ERROR;
	}		
	return OK;
}

int set_name_team(int pos, char **src, t_env *e, int ac)
{
	int it = pos + 1;

	if (pos + 1 >= ac)
		return ERROR;
	while (it < ac && src[it][0] != '-') {
		if ((e->name = add_name(e->name, src[it],
					e->nbClient)) == NULL)
			return ERROR;
		it += 1;
	}
	return OK;	
}

int set_client_nb(int pos, char **src, t_env *e, int ac)
{
	if (pos + 1 >= ac)
		return ERROR;
	e->nbClient = atoi(src[pos + 1]);
	if (e->nbClient < 1 ||
	    check_alpha(src[pos + 1]) == ERROR)
		return ERROR;
	return OK;	
}

int set_freq(int pos, char **src, t_env *e, int ac)
{
	if (pos + 1 >= ac)
		return ERROR;
	e->freq = atoi(src[pos + 1]);
	if (e->freq < 1 ||
	    check_alpha(src[pos + 1]) == ERROR)
		return ERROR;
	return OK;
}

