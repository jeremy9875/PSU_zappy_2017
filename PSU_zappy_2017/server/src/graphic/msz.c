/*
** EPITECH PROJECT, 2018
** map_functions.c
** File description:
** map_functions.c
*/

#include <stdio.h>
#include "struct.h"

void msz_function(t_env *e, char *cmd, int fd)
{
	(void)cmd;
	dprintf(fd, "msz %d, %d\n", e->x, e->y);
}
