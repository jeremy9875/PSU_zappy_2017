/*
** EPITECH PROJECT, 2018
** Ai
** File description:
** zappy
*/

#ifndef AI_HPP_
# define AI_HPP_

# include <iostream>
# include <map>
# include "Player.hpp"
# include "Data.hpp"

# define _LOOK "Look"
# define _FORWARD "Forward"
# define _RIGHT "Right"
# define _LEFT "Left"

class Ai {
public:
	Ai();
	~Ai();
	void GameLoop();
	void setDeath();
	void setPlayerData(Data *data);
	bool _alive = true;
	bool _connected = false;
	std::map<int, std::string> FuncName;
};

#endif /* !AI_HPP_ */
