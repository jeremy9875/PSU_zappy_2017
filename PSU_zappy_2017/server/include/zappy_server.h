/*
** EPITECH PROJECT, 2018
** IRC.h
** File description:
** IRC.h
*/

#ifndef SERVER
# define SERVER

# include "struct.h"
# include "define_server.h"

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* SERVER/CLIENT FUNCTIONS */

int add_server(t_env *);
int add_client(t_env *, int);
int server_read(t_env *, int);
int client_read(t_env *, int);
int client_write(int, char *);

/* UTILS */

int init(t_env *, struct timeval *, char **, int);
void init_client_struct(t_client *);
int check_alpha(char *);
int check_struct(t_env *);
char *treat_line(char *, int);

/* PARSING */

int parse_command(t_env *);

/* UPDATE FUNCTIONS */

void update_position(t_env *, char *, int);
void update_orientation(t_env *, char *, int);
void send_inventory(t_env *, char *, int);
void look(t_env *, char *, int);
void take_object(t_env *, char *, int);
void set_object(t_env *, char *, int);

/* GRAPHICS */

void msz_function(t_env *, char *, int);
void bct_function(t_env *, char *, int);
void mct_function(t_env *, char *, int);

/* LISTE CHAINEE*/

element *delete_msg(element *);
element *add_msg(element *, char *, int);
element *add_name(element *, char *, int);
t_bloc *add_bloc(t_bloc *, t_env *, int, int);
element *print_list(element *);

/* SET */

int set_port(int, char **, t_env *, int);
int set_width_height(int, char **, t_env *, int);
int set_name_team(int, char **, t_env *, int);
int set_client_nb(int, char **, t_env *, int);
int set_freq(int, char **, t_env *, int);
int welcome(int, t_env *);

/* BLOCS FUNCTIONS */

int get_player_x(t_env *, int);
int get_player_y(t_env *, int);
t_bloc *set_player_x(t_env *, int, int , int);
t_bloc *set_player_y(t_env *, int, int , int);

#endif /* !SERVER */
