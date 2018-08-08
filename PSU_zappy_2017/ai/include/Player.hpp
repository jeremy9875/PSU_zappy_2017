/*
** EPITECH PROJECT, 2018
** player
** File description:
** zappy
*/

#include "bloc.hpp"

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

class Player {
public:
	bool is_empty;
	std::vector<int> _playerNb;
	std::vector<int> _playerLevel;
	struct X _dir;
	std::vector<int> _ressourceNb;
	std::vector<std::string> _message;
	bool _incantationFinish;
	void setPlayerNb(int nb);
	bool getPlayerNb(int nb);
	void setPlayerLev(int nb);
	Player() = default;
	~Player() = default;
private:
};

#endif /* !PLAYER_HPP_ */
