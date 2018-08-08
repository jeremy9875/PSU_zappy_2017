/*
** EPITECH PROJECT, 2018
** server_function.c
** File description:
** server_function.c
*/

#include <sys/socket.h>
#include "zappy_server.h"
#include "define_server.h"


int add_client(t_env *e, int s)
{
	int cs;
	struct sockaddr_in client_sin;
	socklen_t client_sin_len;
	
	client_sin_len = sizeof(client_sin);
	client_sin.sin_family = AF_INET;
        client_sin.sin_port = htons(e->port);
        client_sin.sin_addr.s_addr = INADDR_ANY;
	if ((cs = accept(s, (struct sockaddr *)&client_sin
			 , &client_sin_len)) == -1)
		return ERROR;
	e->fd_type[cs] = FD_CLIENT;
	e->fct_read[cs] = client_read;
	e->fct_write[cs] = client_write;
	init_client_struct(&e->client[cs]);
	e->bloc = add_bloc(e->bloc, e, cs, 7);
	if (welcome(cs, e) == ERROR) {
		e->fd_type[cs] = FD_FREE;
		close(cs);
	}
	return OK;
}

int client_write(int fd, char *msg)
{
	dprintf(fd, "%s", msg);
	return OK;
}

int client_read(t_env *e, int fd)
{
	int r;
	char buf[BUF_SIZE];

	r = read(fd, buf, BUF_SIZE);
	if (r > 0) {
		buf[r] = '\0';
		e->msg = add_msg(e->msg, buf, fd);
	} else {
		if (close(fd) == -1)
			return ERROR;
		e->fd_type[fd] = FD_FREE;
	}
	return OK;
}
