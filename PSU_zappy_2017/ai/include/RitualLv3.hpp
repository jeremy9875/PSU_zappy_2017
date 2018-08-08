/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** RitualLv3
*/

#ifndef _RITUAL_LV3_HPP_
# define _RITUAL_LV3_HPP_

# include "Ritual.hpp"
# include <vector>
# include <map>
# include <iostream>
# include <string>

# define PLAYER "player"
# define LINEMATE "linemate"
# define DERAUMERE "deraumere"
# define SIBUR "sibur"
# define MENDIANE "mendiane"
# define PHIRAS "phiras"
# define THYSTAME "thystame"


 class RitualLv3 : public Ritual
{
public:
	RitualLv3();
	~RitualLv3();
	bool CheckStone(std::vector<std::string>);
	std::map<std::string, int> NeedStone;
};

# endif /* !_RITUAL_LV1_HPP_ */
