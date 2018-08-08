/*
** EPITECH PROJECT, 2018
** Ai
** File description:
** zappy
*/

#include "Ai.hpp"

Ai::Ai()
{
	FuncName[0] = _LOOK;
	FuncName[1] = _FORWARD;
	FuncName[2] = _RIGHT;
	FuncName[3] = _LEFT;
}

Ai::~Ai()
{
}

void Ai::setPlayerData(Data *data)
{
	(void)data;
}

void Ai::GameLoop()
{
	
}

void Ai::setDeath()
{
	_alive = false;
}
