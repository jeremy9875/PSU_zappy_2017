/*
** EPITECH PROJECT, 2018
** inventory_functions.c
** File description:
** inventory_functions.c
*/

#include "zappy_server.h"

void send_inventory(t_env *e, char *cmd, int fd)
{
	(void)cmd;
	dprintf(fd, INVENTORY_REQUEST, e->client[fd].inventory[0],
		e->client[fd].inventory[1],
		e->client[fd].inventory[2],
		e->client[fd].inventory[3],
		e->client[fd].inventory[4],
		e->client[fd].inventory[5],
		e->client[fd].life);
}
