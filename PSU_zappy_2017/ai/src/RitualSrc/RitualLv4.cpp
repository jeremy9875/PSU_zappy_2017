/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** RitualLv4
*/

#include "RitualLv4.hpp"

RitualLv4::RitualLv4()
{
	NeedStone[PLAYER] = 4;
	NeedStone[LINEMATE] = 1;
	NeedStone[DERAUMERE] = 1;
	NeedStone[SIBUR] = 2;
	NeedStone[MENDIANE] = 0;
	NeedStone[PHIRAS] = 1;
	NeedStone[THYSTAME] = 0;
}

RitualLv4::~RitualLv4()
{
	NeedStone.clear();
}

bool RitualLv4::CheckStone(std::vector<std::string> ResourceData)
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
