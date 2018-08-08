/*
** EPITECH PROJECT, 2018
** Connect
** File description
** zappy
*/

#ifndef CONNECT_HPP_
# define CONNECT_HPP_

#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <iostream>
#include <functional>
#include "graphic.hpp"

# define BUFF_MAX 4096

class Data
{
public:
        Data();
        ~Data();
        void set_name(std::string);
        void set_machine(std::string);
        void set_sfd(int);
        void set_port(int);
        void set_ip(std::string);
        void set_fd(fd_set);
        void set_sock(struct sockaddr_in);
        void set_timev(struct timeval);
        int  get_sfd(void);
        struct timeval  get_tv(void);
        fd_set get_fdread(void);
        int init(zappyWin *zappy);
        std::string pos;
  zappyWin *_zappy;
        std::string playerNb;
        int sfd;
        std::string name;
private:
        std::string machine;
        int port;
        std::string ip;
        struct sockaddr_in cliAddr;
        fd_set fd_read;
        struct timeval tv;
};

int client_loop(Data *data);
bool checkstr(std::string);
void read_server(int);
void read_client(Data *);

#endif /* CONNECT_HPP_ */
