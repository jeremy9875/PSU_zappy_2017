/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** RitualLv6
*/

#ifndef _RITUAL_LV6_HPP_
# define _RITUAL_LV6_HPP_

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


class RitualLv6 : public Ritual
{
public:
	RitualLv6();
	~RitualLv6();
	bool CheckStone(std::vector<std::string>);
	std::map<std::string, int> NeedStone;
};

# endif /* !_RITUAL_LV1_HPP_ */
