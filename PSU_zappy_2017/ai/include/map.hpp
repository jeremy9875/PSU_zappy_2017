/*
** EPITECH PROJECT, 2018
** map
** File description:
** zappy
*/

#include <iostream>

#ifndef MAP_HPP_
# define MAP_HPP_

class Map {
public:
	int x;
	int y;
	Map() = default;
	~Map() = default;
	void set(int x, int y);
	int get_y();
	int get_x();
private:
};

#endif /* !MAP_HPP_ */
