/*
** EPITECH PROJECT, 2018
** graphic
** File description:
** zappy
*/

#ifndef GRAPHIC_HPP_
# define GRAPHIC_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "map.hpp"

class zappyWin {
public:
  zappyWin();
  ~zappyWin();
  sf::Event _event;
  sf::RenderWindow *_window;
  sf::Texture _texture;
  sf::Font _font;
  Map _map;
  int _x;
  int _y;
  int _xmax;
  int _ymax;
  int _xtemp;
  int _ytemp;
  int _ytmp;
  int _sfd;
  std::string _Ip;
  std::string _Port;
  void createBloc(int x, int y);
  void setSfd(int sfd);
  int getSfd(void);
  std::string _sendGet(std::string str);
  int getMsz(void);
  int getMct(void);
  void createFood(int x, int y);
  void createLineMate(int x, int y);
  void createPlayer(int x, int y);
  void createDeraumere(int x, int y);
  void createMendiane(int x, int y);
  void createPhiras(int x, int y);
  void createSibur(int x, int y);
  void createThystame(int x, int y);
};

void drawButton(zappyWin *zappy, int x, int y);
void inputIp(zappyWin *zappy);
void loadBackground(zappyWin *zappy);
void createConnect(zappyWin *zappy);
void connect(zappyWin *zappy);
bool CreateWindow();

#endif /* !GRAPHIC_HPP_ */
