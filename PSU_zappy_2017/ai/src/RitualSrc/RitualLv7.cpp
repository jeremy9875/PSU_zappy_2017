/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** RitualLv7
*/

#include "RitualLv7.hpp"

RitualLv7::RitualLv7()
{
	NeedStone[PLAYER] = 6;
	NeedStone[LINEMATE] = 2;
	NeedStone[DERAUMERE] = 2;
	NeedStone[SIBUR] = 2;
	NeedStone[MENDIANE] = 2;
	NeedStone[PHIRAS] = 2;
	NeedStone[THYSTAME] = 1;
}

RitualLv7::~RitualLv7()
{
	NeedStone.clear();
}

bool RitualLv7::CheckStone(std::vector<std::string> ResourceData)
{
	std::string check;
	std::string nb;

	for (size_t i = 0; i < ResourceData.size(); ++i) {
		check = ResourceData[i].substr(0, (ResourceData[i].find(" ") - 1));
		nb = ResourceData[i].substr(ResourceData[i].find(" "));
		if (stod(nb) != NeedStone[check])
			return false;
	}
	return true;
}
