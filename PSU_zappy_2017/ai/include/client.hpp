/*
** EPITECH PROJECT, 2018
** client.hpp
** File description:
** client.hpp
*/

#ifndef CLIENT_HPP_
# define CLIENT_HPP_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <string.h>
# include <iostream>
# include "Ai.hpp"
# include "Data.hpp"

# define BUFF_MAX 4096

void read_server(int);
void read_client(Data*, Ai*);
bool getWelcome(Data*, bool);

#endif /* !CLIENT_HPP_ */
