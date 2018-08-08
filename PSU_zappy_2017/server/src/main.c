/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <time.h>
#include "zappy_server.h"
#include "define_server.h"
#include "usage.h"

int usage(char *exec_name)
{
	printf(USAGE);
	printf("%s", exec_name);
	printf(USAGE1);
	printf(PORT);
	printf(WIDTH);
	printf(HEIGHT);
	printf(NAME);
	printf(CLIENTNB);
	printf(FREQ);
	return OK;
}

int server(t_env e, struct timeval tv)
{
	fd_set fd_read;
	int fd_max;
	int i = 0;

	while (1) {
		FD_ZERO(&fd_read);
		fd_max = 0;
		for (i = 0; i < MAX_FD; i++)
			if (e.fd_type[i] != FD_FREE) {
				FD_SET(i, &fd_read);
				fd_max = i;
			}
		if (select(fd_max + 1, &fd_read, NULL, NULL, &tv) == -1)
			perror(SELECT_ERROR);
		for (i = 0; i < MAX_FD; i++)
			if (FD_ISSET(i, &fd_read))
				e.fct_read[i](&e, i);
		parse_command(&e);
	}
	return (OK);
}

int main(int ac, char **av)
{
	t_env e;
	struct timeval tv;
	
	if (ac == 2)
		if (strcmp(av[1], "--help") == 0 ||
		    strcmp(av[1], "-help") == 0 ||
		    strcmp(av[1], "-h") == 0)
			return usage(av[0]);
	if (ac < ARG_NB)
		return ERROR;
	if (init(&e, &tv, av, ac) == ERROR)
		return ERROR;
	if (server(e, tv) == ERROR)
		return ERROR;
	return OK;
}
