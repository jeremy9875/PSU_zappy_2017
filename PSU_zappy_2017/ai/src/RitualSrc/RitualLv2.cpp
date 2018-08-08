/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** RitualLv2
*/

#include "RitualLv2.hpp"

RitualLv2::RitualLv2()
{
	NeedStone[PLAYER] = 2;
	NeedStone[LINEMATE] = 1;
	NeedStone[DERAUMERE] = 1;
	NeedStone[SIBUR] = 1;
	NeedStone[MENDIANE] = 0;
	NeedStone[PHIRAS] = 0;
	NeedStone[THYSTAME] = 0;
}

RitualLv2::~RitualLv2()
{
	NeedStone.clear();
}

bool RitualLv2::CheckStone(std::vector<std::string> ResourceData)
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
