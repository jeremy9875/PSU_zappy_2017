/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** init.c
*/

#include <time.h>
#include <stdarg.h>
#include "zappy_server.h"
#include "define_server.h"

const t_option option[6] =
{
	{"-p", set_port},
	{"-x", set_width_height},
	{"-y", set_width_height},
	{"-n", set_name_team},
	{"-c", set_client_nb},
	{"-f", set_freq},
};

int init_loop(int ac, char **av, t_env *e)
{
	int it = 1;
	int check = 0;

	while (it < ac) {
		while (check <= NB_COMMAND) {
			if (strcmp(av[it], option[check].option) == 0) {
				if (option[check].func(it, av, e, ac) == ERROR)
					return ERROR;
			}
			check += 1;
		}
		it += 1;
		check = 0;
	}
	return OK;
}

void init_struct(t_env *e, struct timeval *tv)
{
	tv->tv_sec = 20;
	tv->tv_usec = 0;
	e->msg = NULL;
	e->port = -1;
	e->x = -1;
	e->y = -1;
	e->name = NULL;
	e->bloc = NULL;
	e->nbClient = -1;
	e->freq = -1;
}

element *init_name(t_env *e)
{
	element *tmp = e->name;

	tmp->fd = e->nbClient;
	while (tmp->nxt != NULL) {
		tmp->fd = e->nbClient;
		tmp = tmp->nxt;
	}
	return tmp;
}

int init(t_env *e, struct timeval *tv, char **args, int ac)
{
	init_struct(e, tv);
	if (init_loop(ac, args, e) == ERROR ||
	    memset(e->fd_type, FD_FREE, MAX_FD) == NULL ||
	    check_struct(e) == ERROR)
		return ERROR;
	if (add_server(e) == ERROR)
		return ERROR;
	e->name = init_name(e);
        return OK;
}

void init_client_struct(t_client *client)
{
	srand(time(NULL));
	client->orientation = rand() % 4;
	client->lvl = 1;
	client->inventory[0] = 0;
	client->inventory[1] = 0;
	client->inventory[2] = 0;
	client->inventory[3] = 0;
	client->inventory[4] = 0;
	client->inventory[5] = 0;
	client->life = 1260;
	client->work = 0;
	client->incantation = false;
}
