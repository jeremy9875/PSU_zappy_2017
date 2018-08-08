/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** RitualLv3
*/

#include "RitualLv3.hpp"

RitualLv3::RitualLv3()
{
	NeedStone[PLAYER] = 2;
	NeedStone[LINEMATE] = 2;
	NeedStone[DERAUMERE] = 0;
	NeedStone[SIBUR] = 1;
	NeedStone[MENDIANE] = 0;
	NeedStone[PHIRAS] = 2;
	NeedStone[THYSTAME] = 0;
}

RitualLv3::~RitualLv3()
{
	NeedStone.clear();
}

bool RitualLv3::CheckStone(std::vector<std::string> ResourceData)
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
