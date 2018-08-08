/*
** EPITECH PROJECT, 2018
** set_obj_function.c
** File description:
** set_obj_function.c
*/

#include <time.h>
#include <stdio.h>
#include "struct.h"
#include "zappy_server.h"

t_bloc *add_bloc_at_pos(t_env *e, int type, int x, int y)
{
        t_bloc *new;

        srand(time(NULL));
        if ((new = malloc(sizeof(t_bloc))) == NULL)
		return NULL;
        new->x = x;
        new->y = y;
        new->active = true;
	new->type = type;
        new->fd = -1;
        new->nxt = NULL;
        if (e->bloc != NULL) {
		t_bloc *tmp = e->bloc;
                while (tmp->nxt != NULL)
                        tmp = tmp->nxt;
                tmp->nxt = new;
                return e->bloc;
        }
	return new;
}

void set_object(t_env *e, char *cmd, int fd)
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
	if (e->client[fd].inventory[obj_numb] >= 1) {
		e->bloc = add_bloc_at_pos(e, obj_numb, x, y);
		e->client[fd].inventory[obj_numb] -= 1;
		dprintf(fd, "ko\n");
	} else
		dprintf(fd, "ko\n");
	
		
}


