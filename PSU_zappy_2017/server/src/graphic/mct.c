/*
** EPITECH PROJECT, 2018
** mct.c
** File description:
** mct.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

char *detail_tile(t_env *e, int type, int x, int y)
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


void mct_function(t_env *e, char *cmd, int fd)
{
        int x = 0;
        int y = 0;
	char *info;

	(void)cmd;
	while (y < e->y) {
		while (x < e->x) {
			if ((info = malloc(sizeof(char) * BUF_SIZE)) == NULL)
				return ;
			strcat(info, "bct ");
			strcat(info, detail_tile(e, 6, x, y));
			strcat(info, " ");
			strcat(info, detail_tile(e, 0, x, y));
			strcat(info, " ");
			strcat(info, detail_tile(e, 1, x, y));
			strcat(info, " ");
			strcat(info, detail_tile(e, 2, x, y));
			strcat(info, " ");
			strcat(info, detail_tile(e, 3, x, y));
			strcat(info, " ");
			strcat(info, detail_tile(e, 4, x, y));
			strcat(info, " ");
			strcat(info, detail_tile(e, 5, x, y));
			dprintf(fd, "%s\n", info);
			x += 1;
			free(info);
		}
		y += 1;
		x = 0;
	}
}
