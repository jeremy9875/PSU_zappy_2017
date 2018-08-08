/*
** EPITECH PROJECT, 2018
** map
** File description:
** zappy
*/

#include <iostream>
#include <vector>

#ifndef MAP_HPP_
# define MAP_HPP_

class Map {
public:
  std::vector<int> x;
  std::vector<int> y;
  std::vector<bool> q0;
  std::vector<bool> q1;
  std::vector<bool> q2;
  std::vector<bool> q3;
  std::vector<bool> q4;
  std::vector<bool> q5;
  std::vector<bool> q6;
	Map() = default;
	~Map() = default;
  void set(int x, int y);
  int get_y(int nb);
  int get_x(int nb);
  bool get_q0(int nb);
  bool get_q1(int nb);
  bool get_q2(int nb);
  bool get_q3(int nb);
  bool get_q4(int nb);
  bool get_q5(int nb);
  bool get_q6(int nb);
private:
};

#endif /* !MAP_HPP_ */
