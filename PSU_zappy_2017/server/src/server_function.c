/*
** EPITECH PROJECT, 2018
** server_function.c
** File description:
** server_function.c
*/

#include "zappy_server.h"
#include "define_server.h"

int team_number(t_env *e)
{
	int nb  = 0;
	element *tmp = e->name;

	while (tmp->nxt != NULL) {
		tmp = tmp->nxt;
		nb += 1;
	}
	return nb;
}

int add_server(t_env *e)
{
	int s;
	struct sockaddr_in sin;

	if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		return ERROR;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(e->port);
	sin.sin_addr.s_addr = INADDR_ANY;
	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1 ||
	    listen(s, e->nbClient * team_number(e)) == -1)
		return ERROR;
	e->fd_type[s] = FD_SERVER;
	e->fct_read[s] = server_read;
	e->fct_write[s] = NULL;
	return OK;
}

int server_read(t_env *e, int fd)
{
	if (add_client(e, fd) == ERROR)
		return ERROR;
	return OK;
}
