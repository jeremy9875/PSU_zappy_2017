/*
** EPITECH PROJECT, 2018
** object_functions.c
** File description:
** object_functions.c
*/

#include <stdio.h>
#include "struct.h"
#include "define_server.h"
#include "zappy_server.h"

t_bloc *delete_tile(t_bloc *list, int x, int y, int obj_numb)
{
	if (!list)
		return NULL;
	if (list->x == x && list->y == y && list->type == obj_numb) {
		t_bloc *tmp = list->nxt;
		free(list);
		tmp = delete_tile(tmp, x, y, obj_numb);
		return tmp;
	} else {
		list->nxt = delete_tile(list, x, y, obj_numb);
		return list;
	}
		
}

int check_tile(t_env *e, int x, int y, int obj_numb)
{
	t_bloc *tmp = e->bloc;
        
	while (tmp != NULL) {
		if ((tmp->x == x) && (tmp->y == y) &&
		    (tmp->type == obj_numb)) 
			return OK;
		tmp = tmp->nxt;
	}
	return ERROR;
}

void take_object(t_env *e, char *cmd, int fd)
{
	int x = get_player_x(e, fd);
	int y = get_player_y(e, fd);
	char *object = treat_line(cmd, 4);
	int it = 0;
	int obj_numb = 0;

	while (it < 7) {
		if (strcmp(object, bloc[it]) == 0)
			obj_numb = it;
		it += 1;
	}
	if (check_tile(e, x, y, obj_numb) == ERROR)
		dprintf(fd, "ko\n");
	else {
		delete_tile(e->bloc, x, y, obj_numb);
		e->client[fd].inventory[obj_numb] += 1;
		dprintf(fd, "ok\n");
	}
}
