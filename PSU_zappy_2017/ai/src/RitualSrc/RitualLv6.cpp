/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** RitualLv6
*/

#include "RitualLv6.hpp"

RitualLv6::RitualLv6()
{
	NeedStone[PLAYER] = 6;
	NeedStone[LINEMATE] = 1;
	NeedStone[DERAUMERE] = 2;
	NeedStone[SIBUR] = 3;
	NeedStone[MENDIANE] = 0;
	NeedStone[PHIRAS] = 1;
	NeedStone[THYSTAME] = 0;
}

RitualLv6::~RitualLv6()
{
	NeedStone.clear();
}

bool RitualLv6::CheckStone(std::vector<std::string> ResourceData)
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
