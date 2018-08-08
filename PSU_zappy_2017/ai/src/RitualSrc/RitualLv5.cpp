/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** RitualLv5
*/

#include "RitualLv5.hpp"

RitualLv5::RitualLv5()
{
	NeedStone[PLAYER] = 4;
	NeedStone[LINEMATE] = 1;
	NeedStone[DERAUMERE] = 2;
	NeedStone[SIBUR] = 1;
	NeedStone[MENDIANE] = 3;
	NeedStone[PHIRAS] = 0;
	NeedStone[THYSTAME] = 0;
}

RitualLv5::~RitualLv5()
{
	NeedStone.clear();
}

bool RitualLv5::CheckStone(std::vector<std::string> ResourceData)
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
