/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** list.c
*/

#include <time.h>
#include "zappy_server.h"
#include "define_server.h"

element *add_name(element *list, char *name, int nbClient)
{
	element *new;
	
	if ((new = malloc(sizeof(element))) == NULL)
		return NULL;
	strcpy(new->msg, name);
	new->fd = nbClient;
	new->nxt = NULL;
	if (list != NULL) {
		element *tmp = list;
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = new;
		return list;
	}
	return new;
}

element *add_msg(element *list, char *_msg, int _fd)
{
	element *new;

	if ((new = malloc(sizeof(element))) == NULL)
		return NULL;
	strcpy(new->msg, _msg);
	new->fd = _fd;
	new->nxt = NULL;
	if (list != NULL) {
		element *tmp = list;
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = new;
		return list;
	}
	return new;
}

t_bloc *add_bloc(t_bloc *list, t_env *e, int fd, int type)
{
	t_bloc *new;

	srand(time(NULL));
	if ((new = malloc(sizeof(t_bloc))) == NULL)
		return NULL;
	new->x = rand() % e->x;
	new->y = rand() % e->y;
	new->active = true;
	new->type = type;
	new->fd = fd;
	new->nxt = NULL;
	if (list != NULL) {
		t_bloc *tmp = list;
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = new;
		return list;
	}
	return new;
}

element *delete_msg(element *list)
{
	if (list == NULL)
		return NULL;
	if (list->msg != NULL) {
		element *tmp = list->nxt;
		free(list);
		tmp = delete_msg(tmp);
		return tmp;
	} else {
		list->nxt = delete_msg(list->nxt);
		return list;
	}
}
