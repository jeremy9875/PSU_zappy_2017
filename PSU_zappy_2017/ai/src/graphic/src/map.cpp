/*
** EPITECH PROJECT, 2018
** map
** File description:
** zappy
*/

#include "map.hpp"

void Map::set(int x, int y)
{
  this->x.push_back(x);
  this->y.push_back(y);
}

int Map::get_x(int nb)
{
	return this->x[nb];
}

int Map::get_y(int nb)
{
	return this->y[nb];
}

bool Map::get_q0(int nb)
{
	return this->q0[nb];
}

bool Map::get_q1(int nb)
{
	return this->q1[nb];
}

bool Map::get_q2(int nb)
{
	return this->q2[nb];
}

bool Map::get_q3(int nb)
{
	return this->q3[nb];
}

bool Map::get_q4(int nb)
{
	return this->q4[nb];
}

bool Map::get_q5(int nb)
{
	return this->q5[nb];
}

bool Map::get_q6(int nb)
{
	return this->q6[nb];
}
