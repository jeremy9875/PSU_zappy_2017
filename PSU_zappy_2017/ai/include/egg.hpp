/*
** EPITECH PROJECT, 2018
** egg
** File description:
** zappy
*/

#include "bloc.hpp"

#ifndef EGG_HPP_
# define EGG_HPP_

class Egg {
public:
	bool is_empty;
	std::vector<int> _eggNb;
	void set_egg(int nb);
	void remove_egg(int nb);
	Egg() = default;
	~Egg() = default;
private:
};

#endif /* !EGG_HPP_ */
