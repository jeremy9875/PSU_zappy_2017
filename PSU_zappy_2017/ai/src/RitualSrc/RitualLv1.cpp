/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** RitualLv1
*/

#include "RitualLv1.hpp"

RitualLv1::RitualLv1()
{
	NeedStone[PLAYER] = 1;
	NeedStone[LINEMATE] = 1;
	NeedStone[DERAUMERE] = 0;
	NeedStone[SIBUR] = 0;
	NeedStone[MENDIANE] = 0;
	NeedStone[PHIRAS] = 0;
	NeedStone[THYSTAME] = 0;
}

RitualLv1::~RitualLv1()
{
	NeedStone.clear();
}

bool RitualLv1::CheckStone(std::vector<std::string> ResourceData)
{
	std::string check;
	std::string nb;

	for (size_t i = 0; i < ResourceData.size(); ++i) {
		check = ResourceData[i].substr(0, (ResourceData[i].find(" ") - 1));
		nb = ResourceData[i].substr(ResourceData[i].find(" "));
		if (NeedStone[check])
			if (stod(nb) != NeedStone[check])
				return false;
	}
	return true;
}
