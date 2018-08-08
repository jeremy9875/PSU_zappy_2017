/*
** EPITECH PROJECT, 2018
** read_functions.cpp
** File description:
** read_functions.cpp
*/

#include "client.hpp"
#include "Data.hpp"
#include "irc.hpp"
#include "Player.hpp"
#include "Ai.hpp"

void read_client(Data *data, Ai *_Ai)
{
	Player player;

	data->playerNb = "10";
	data->pos = "10 10";
	_Ai->setPlayerData(data);
	player._sfd = data->get_sfd();
	player.Call(_Ai->FuncName[0]);
}

void read_server(int fd)
{
	int end;
	char buffer[1000];

	end = read(fd, buffer, 1000);
	if (end > 0) {
		buffer[end] = '\0';
		std::cout << buffer << std::endl;
	}
}

bool getWelcome(Data *data, bool connection)
{
	std::string buffer = "";

	std::getline(std::cin, buffer);
	if (buffer == "WELCOME\n")
		dprintf(data->sfd, "%s\n", data->name.c_str());
	std::getline(std::cin, buffer);
	data->playerNb = buffer;
	std::getline(std::cin, buffer);
	data->pos = buffer;
	if (!connection)
		connection = true;
	return true;
}
