/*
** EPITECH PROJECT, 2018
** zappy_Win
** File description:
** zappy
*/

#include "graphic.hpp"

zappyWin::zappyWin()
{
  _x = 150;
  _y = 330;
  _xmax = 330;
  _ymax = 780;
  _window = new sf::RenderWindow;
  _font.loadFromFile("./ressource/font/BebasNeue-Regular.ttf");
}

zappyWin::~zappyWin()
{
  _window->close();
}

void zappyWin::setSfd(int sfd)
{
  _sfd = sfd;
}

int zappyWin::getSfd(void)
{
  return _sfd;
}

std::string zappyWin::_sendGet(std::string str)
{
  char buffer[1000];
  std::string tmp;

  dprintf(this->_sfd, "%s\n", str.c_str());
  usleep(10);
  int end = read(_sfd, buffer, 1000);
  str[end] = '\0';
  tmp = std::string(buffer);

  return tmp;
}

int zappyWin::getMsz(void)
{
  std::string str;
  std::string::size_type posx;
  std::string tmp;
  int x;
  int y;

  str = _sendGet("msz");
  posx = str.find(',');
  tmp = str.substr(4, 2);
  x = std::stoi(tmp) * 64;
  tmp = str.substr(posx + 2, str.size());
  y = std::stoi(tmp) * 64;
  _map.set(x, y);
  _xmax = x * 64;
  _ymax = y * 64;
  return 0;
}

int zappyWin::getMct(void)
{
  std::string str;
  std::string tmp;
  std::string::size_type posqf;
  std::string::size_type posql;
  int q0;
  int q1;
  int q2;
  int q3;
  int q4;
  int q5;
  int q6;

  str = _sendGet("mct");
  posqf = 4;
  std::cout << str << std::endl;
  /*posql = str.find_first_of('\n', posqf);
  tmp = str.substr(posqf, 1);
  q0 = std::stoi(tmp);
  tmp = str.substr(posqf + 2, 1);
  q1 = std::stoi(tmp);
  tmp = str.substr(posqf + 4, 1);
  q2 = std::stoi(tmp);
  tmp = str.substr(posqf + 6, 1);
  q3 = std::stoi(tmp);
  tmp = str.substr(posqf + 8, 1);
  q4 = std::stoi(tmp);
  tmp = str.substr(posqf + 10, 1);
  q5 = std::stoi(tmp);
  tmp = str.substr(posqf + 12, posql);
  q6 = std::stoi(tmp);
  if (q0 <= 0)
    _map.q0.push_back(false);
  else
    _map.q0.push_back(true);
  if (q1 <= 0)
    _map.q1.push_back(false);
  else
    _map.q1.push_back(true);
  if (q2 <= 0)
    _map.q2.push_back(false);
  else
    _map.q2.push_back(true);
  if (q3 <= 0)
    _map.q3.push_back(false);
  else
    _map.q3.push_back(true);
  if (q4 <= 0)
    _map.q4.push_back(false);
  else
    _map.q4.push_back(true);
  if (q5 <= 0)
    _map.q5.push_back(false);
  else
    _map.q5.push_back(true);
  if (q6 <= 0)
    _map.q6.push_back(false);
  else
  _map.q6.push_back(true);*/
  return 0;
}

void zappyWin::createBloc(int x, int y)
{
  sf::RectangleShape bloc;
  sf::Texture tile;

  if (!tile.loadFromFile("./ressource/img/tiles.png"))
    _window->close();
  bloc.setSize(sf::Vector2f(64, 64));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setTexture(&tile);
  bloc.setPosition(x, y);
  _window->draw(bloc);
}

void zappyWin::createFood(int x, int y)
{
  sf::RectangleShape bloc;
  sf::Texture tile;

  if (!tile.loadFromFile("./ressource/img/carrot.png"))
    _window->close();
  bloc.setSize(sf::Vector2f(16, 16));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setTexture(&tile);
  _xtemp = _x;
  _ytemp = _y;
  _x = x + 16;
  bloc.setPosition(x, y);
  _window->draw(bloc);
}

void zappyWin::createLineMate(int x, int y)
{
  sf::RectangleShape bloc;
  sf::Texture tile;

  if (!tile.loadFromFile("./ressource/img/linemate.png"))
    _window->close();
  bloc.setSize(sf::Vector2f(16, 16));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setTexture(&tile);
  _x = x + 16;
  bloc.setPosition(x, y);
  _window->draw(bloc);
}

void zappyWin::createDeraumere(int x, int y)
{
  sf::RectangleShape bloc;
  sf::Texture tile;

  if (!tile.loadFromFile("./ressource/img/deraumere.png"))
    _window->close();
  bloc.setSize(sf::Vector2f(16, 16));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setTexture(&tile);
  _x = x + 16;
  bloc.setPosition(x, y);
  _window->draw(bloc);
}

void zappyWin::createMendiane(int x, int y)
{
  sf::RectangleShape bloc;
  sf::Texture tile;

  if (!tile.loadFromFile("./ressource/img/mendiane.png"))
    _window->close();
  bloc.setSize(sf::Vector2f(16, 16));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setTexture(&tile);
  _x = _xtemp;
  _xtemp = _x;
  _y = y + 16;
  bloc.setPosition(x, y);
  _window->draw(bloc);
}

void zappyWin::createPhiras(int x, int y)
{
  sf::RectangleShape bloc;
  sf::Texture tile;

  if (!tile.loadFromFile("./ressource/img/phiras.png"))
    _window->close();
  bloc.setSize(sf::Vector2f(16, 16));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setTexture(&tile);
  _x = x + 16;
  bloc.setPosition(x, y);
  _window->draw(bloc);
}

void zappyWin::createSibur(int x, int y)
{
  sf::RectangleShape bloc;
  sf::Texture tile;

  if (!tile.loadFromFile("./ressource/img/sibur.png"))
    _window->close();
  bloc.setSize(sf::Vector2f(16, 16));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setTexture(&tile);
  _x = x + 16;
  bloc.setPosition(x, y);
  _window->draw(bloc);
}

void zappyWin::createThystame(int x, int y)
{
  sf::RectangleShape bloc;
  sf::Texture tile;

  if (!tile.loadFromFile("./ressource/img/thystame.png"))
    _window->close();
  bloc.setSize(sf::Vector2f(16, 16));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setTexture(&tile);
  _x = x + 16;
  bloc.setPosition(x, y);
  _window->draw(bloc);
}

void zappyWin::createPlayer(int x, int y)
{
  sf::RectangleShape bloc;
  sf::Texture tile;

  if (!tile.loadFromFile("./ressource/img/blocky.png"))
    _window->close();
  bloc.setSize(sf::Vector2f(16, 16));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setTexture(&tile);
  bloc.setPosition(x, y);
  _window->draw(bloc);
  if (x == _xmax) {
    _y = _ytemp + 64;
    _x = 100;
  }
  else {
    _y = _ytemp;
    _x = _xtemp + 64;
  }
}
