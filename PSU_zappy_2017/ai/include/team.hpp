/*
** EPITECH PROJECT, 2018
** team
** File description:
** zappy
*/

#include "bloc.hpp"
#include "player.hpp"
#include "egg.hpp"

#ifndef TEAM_HPP_
# define TEAM_HPP_

class Team {
public:
	std::vector<std::string> _teamName;
	void removeTeam(std::string nb);
	unsigned int _time;
	Player _player;
	Egg _egg;
	Team(void) = default;
	~Team(void) = default;
private:
};

#endif /* !TEAM_HPP_ */
