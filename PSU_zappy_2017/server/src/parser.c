/*
** EPITECH PROJECT, 2018
** parser.c
** File description:
** parser.c
*/

#include <stdlib.h>
#include "struct.h"
#include "zappy_server.h"

const t_command commands[11] =
{
	{"Forward\n", 8, update_position},
	{"Right\n", 6, update_orientation},
	{"Left\n", 5, update_orientation},
	{"Look\n", 5, look},
	{"Inventory\n", 10, send_inventory},
	{"Take\n", 5, take_object},
	{"Set\n", 4, set_object},
	{"msz\n", 4, msz_function},
	{"bct ", 4, bct_function},
	{"mct\n", 4, mct_function},
//	{"Broadcast\n", },
//	{"Connect_nbr\n", },
//	{"Fork\n", },
//	{"Incantation\n", },
};

int parse_command(t_env *e)
{
	int it = 0;
	bool check_cmd = false;

	while (e->msg != NULL) {
		while (it < 10) {
			if (strncmp(commands[it].command, e->msg->msg,
				    commands[it].len) == 0) {
				commands[it].func(e, e->msg->msg, e->msg->fd);
				check_cmd = true;
			}
			it += 1;
		}
		if (!check_cmd)
			dprintf(e->msg->fd, "ko\n");
		check_cmd = false;
		it = 0;
		e->msg = e->msg->nxt;
	}
	return OK;
}
