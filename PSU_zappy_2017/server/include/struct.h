/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <stdbool.h>
# include "define_server.h"

typedef int(*fct)();

/* OPTIONS TAB */

typedef int(*func)();

typedef struct s_option
{
        const char *option;
        func func;
} t_option;

extern const t_option option[6];

extern const char bloc[8][10];

/* PARSER */

typedef void(*func_up)();

typedef struct s_command
{
        const char *command;
	int len;
        func_up func;
} t_command;

extern const t_command commands[11];

/* LISTE CHAINEE */

typedef struct element element;
struct element
{
        char msg[BUF_SIZE];
        int fd;
        struct element *nxt;
};

/* CLIENT */

typedef struct s_client
{
        char team[BUF_SIZE];
	int orientation;
	int lvl;
	int inventory[6];
	int life;
	int work;
	bool incantation;
} t_client;

/* MAP */

typedef struct t_bloc t_bloc;
struct t_bloc
{
	int x;
	int y;
	bool active;
	int type;
	int fd;
	struct t_bloc *nxt;
};

/* SERVER */

typedef struct s_env
{
 	t_client client[MAX_FD];
        char fd_type[MAX_FD];
	fct fct_read[MAX_FD];
        fct fct_write[MAX_FD];
        element *msg;
        int port;
	t_bloc *bloc;
        int x;
        int y;
        element *name;
        int nbClient;
        int freq;
} t_env;

#endif /* !STRUCT_H_ */
