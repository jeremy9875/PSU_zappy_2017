/*
** EPITECH PROJECT, 2018
** client.hpp
** File description:
** client.hpp
*/

#ifndef DATA_HPP_
# define DATA_HPP_

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
	void set_fd(fd_set);
	void set_sock(struct sockaddr_in);
	void set_timev(struct timeval);
	int  get_sfd(void);
	struct timeval  get_tv(void);
	fd_set get_fdread(void);
	void set_client_params(char **);
	int init(char **);
	std::string pos;
	std::string playerNb;
	int sfd;
	std::string name;
private:
	std::string machine;
	int port;
	struct sockaddr_in cliAddr;
	fd_set fd_read;
	struct timeval tv;
};

#endif /* !DATA_HPP_ */
