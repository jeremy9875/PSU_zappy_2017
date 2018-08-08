/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Create window
*/

#include "graphic.hpp"

void drawButton(zappyWin *zappy, int x, int y)
{
  sf::RectangleShape rectangle;

  rectangle.setSize(sf::Vector2f(400, 100));
  rectangle.setOutlineColor(sf::Color::Red);
  rectangle.setOutlineThickness(5);
  rectangle.setPosition(x, y);
  zappy->_window->draw(rectangle);
}

void inputIp(zappyWin *zappy)
{
  sf::String playerInput("");
  sf::Text playerText;

  playerInput += zappy->_event.text.unicode;
  playerText.setFont(zappy->_font);
  playerText.setFillColor(sf::Color::Red);
  playerText.setString(playerInput);
  playerText.setPosition(sf::Vector2f(zappy->_x, zappy->_y));
  if (zappy->_y == 330)
    zappy->_Ip += playerText.getString();
  else if (zappy->_y != 330)
    zappy->_Port += playerText.getString();
  zappy->_window->draw(playerText);
  zappy->_x = zappy->_x + 13;
}

void loadBackground(zappyWin *zappy)
{
  if (!zappy->_texture.loadFromFile("./ressource/img/background.png"))
    zappy->_window->close();
  sf::Sprite background(zappy->_texture);
  background.setScale(sf::Vector2f(1.5f, 1.5f));
  zappy->_window->draw(background);
}

void createConnect(zappyWin *zappy)
{
  sf::Texture connectButton;
  sf::Sprite connectButtonImage;

  if (!connectButton.loadFromFile("./ressource/img/Connect.png"))
    zappy->_window->close();
  connectButtonImage.setPosition(50.0f, 800.0f);
  connectButtonImage.setScale(sf::Vector2f(0.8f, 0.9f));
  connectButtonImage.setTexture(connectButton);
  zappy->_window->draw(connectButtonImage);
}

bool CreateWindow()
{
  zappyWin zappy;

  zappy._window->create(sf::VideoMode(1920, 1080), "Zappy graphic", sf::Style::Fullscreen);
  zappy._window->setFramerateLimit(60);
  loadBackground(&zappy);
  drawButton(&zappy, 100, 300);
  drawButton(&zappy, 100, 500);
  createConnect(&zappy);
  while (zappy._window->isOpen()) {
    while (zappy._window->pollEvent(zappy._event)) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && zappy._y == 330) {
	zappy._y = zappy._y + 200;
	zappy._x = 140;
      }
      else if (zappy._event.type == sf::Event::TextEntered) {
	inputIp(&zappy);
      }
      if (zappy._event.type == sf::Event::MouseButtonPressed) {
	sf::Vector2i LeftMinBord(50,800);
	sf::Vector2i RightMaxBord(770,930);
	if (sf::Mouse::getPosition(zappy._window[0]).x >= LeftMinBord.x
	    && sf::Mouse::getPosition(zappy._window[0]).y >= LeftMinBord.y &&
	    sf::Mouse::getPosition(zappy._window[0]).x <= RightMaxBord.x
	    && sf::Mouse::getPosition(zappy._window[0]).y <= RightMaxBord.y) {
	  connect(&zappy);
	}
      }
      if (zappy._event.type == sf::Event::Closed)
	zappy._window->close();
    }
    zappy._window->display();
  }
  return true;
}

int main(int ac, char **av)
{
  if (ac <= 2 && av)
    CreateWindow();
  else
    return 84;
  return 0;
}
