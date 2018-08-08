/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** main.cpp
*/

#include "irc.hpp"
#include "client.hpp"

int usage(char *str)
{
	std::cout << "USAGE: " << str << " -p port ";
	std::cout << "-n name -h machine\n";
	std::cout <<"\tport\tis the port number\n";
	std::cout << "\tname\tus the name of the team\n";
	std::cout << "\tmachine\tis the name of the ";
	std::cout << "machine; localhost by default\n";
	return OK;
}

int client_loop(Data *data)
{
	fd_set fd;
	Ai _Ai;
	std::string buffer;
	struct timeval tv;

	tv = data->get_tv();
	fd = data->get_fdread();
	while (1) {
/*		FD_ZERO(&fd);
		FD_SET(0, &fd);
		FD_SET(data->get_sfd(), &fd);
		select(data->get_sfd() + 1, &fd, nullptr, nullptr, &tv);
		if (FD_ISSET(0, &fd))*/
		read_client(data, &_Ai);
/*		if (FD_ISSET(data->get_sfd(), &fd))
			read_server(data->get_sfd());*/
	}
	return 0;
}

int main(int ac, char **av)
{
	Data data;

	if (ac == 2) {
		if (strcmp(av[1], "-help") == 0)
			return usage(av[0]);
		else
			return ERROR;
	}
	if (ac != 7)
		return ERROR;
	if (data.init(av) == ERROR)
		return ERROR;
	client_loop(&data);
	return OK;
}
