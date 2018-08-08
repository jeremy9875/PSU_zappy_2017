/*
** EPITECH PROJECT, 2018
** bloc
** File description:
** zappy
*/

#include <iostream>
#include <algorithm>
#include <vector>

#ifndef BLOC_HPP_
# define BLOC_HPP_

class Bloc {
public:
	int x;
	int y;
	int q0;
	int q1;
	int q2;
	int q3;
	int q4;
	int q5;
	int q6;
	void set(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6);
	Bloc(void) = default;
	~Bloc(void) = default;
private:
};

class ListBloc {
public:
	std::vector<Bloc> _BlocList;
	bool _isExist;
	void check(int, int);
	int add(int, int, int, int, int, int, int, int, int);
	ListBloc(void) = default;
	~ListBloc(void) = default;
private:
};

struct X
{
	enum dir { North = '1', East = '2', South = '3', West = '4' };
};

#endif /* !BLOC_HPP_ */
