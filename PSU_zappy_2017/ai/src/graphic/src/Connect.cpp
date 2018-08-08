/*
** EPITECH PROJECT, 2018
** Connect
** File description
** zappy
*/

#include "connect.hpp"
#include "graphic.hpp"

void read_client(Data *client)
{
  int i;

  i = 0;
  client->_zappy->_window->clear(sf::Color::White);
  client->_zappy->_window->display();
  while (client->_zappy->_window->isOpen()) {
    client->_zappy->setSfd(client->get_sfd());
    client->_zappy->_sendGet("test");
    client->_zappy->getMsz();
    while (client->_zappy->_y != client->_zappy->_ymax) {
      client->_zappy->getMct();
      client->_zappy->createBloc(client->_zappy->_x, client->_zappy->_y);
      /*if (client->_zappy->_map.q0[i] && client->_zappy->_map.q0[i] == true)
	client->_zappy->createFood(client->_zappy->_x, client->_zappy->_y);
	if (client->_zappy->_map.q1[i] && client->_zappy->_map.q1[i] == true)
	client->_zappy->createLineMate(client->_zappy->_x, client->_zappy->_y);
	if (client->_zappy->_map.q2[i] && client->_zappy->_map.q2[i] == true)
	client->_zappy->createDeraumere(client->_zappy->_x, client->_zappy->_y);
	if (client->_zappy->_map.q3[i] && client->_zappy->_map.q3[i] == true)
	client->_zappy->createMendiane(client->_zappy->_x, client->_zappy->_y);
	if (client->_zappy->_map.q4[i] && client->_zappy->_map.q4[i] == true)
	client->_zappy->createPhiras(client->_zappy->_x, client->_zappy->_y);
	if (client->_zappy->_map.q5[i] && client->_zappy->_map.q5[i] == true)
	client->_zappy->createSibur(client->_zappy->_x, client->_zappy->_y);
	if (client->_zappy->_map.q6[i] && client->_zappy->_map.q6[i] == true)
	client->_zappy->createThystame(client->_zappy->_x, client->_zappy->_y);
	client->_zappy->createPlayer(client->_zappy->_x, client->_zappy->_y);*/
      client->_zappy->_window->display();
      i++;
    }
  }
}

void read_server(int fd)
{
  (void)fd;
  /*int end;
    std::string buffer[BUFF_MAX];

    end = read(fd, buffer, BUFF_MAX);
    if (end > 0) {
    buffer[end] = '\0';
    std::cout << buffer << std::endl;
    }*/
}

void connect(zappyWin *zappy)
{
  Data client;

  if (checkstr(zappy->_Port) == true || checkstr(zappy->_Ip) == true) {
    zappy->_x = 100;
    zappy->_y = 100;
    client.set_port(std::stoi(zappy->_Port));
    client.set_ip(zappy->_Ip);
    client.init(zappy);
    client_loop(&client);
  }
  else
    zappy->_window->close();
}

int client_loop(Data *data)
{
  fd_set fd;
  struct timeval tv;

  tv = data->get_tv();
  fd = data->get_fdread();
  while (1) {
    FD_ZERO(&fd);
    FD_SET(0, &fd);
    FD_SET(data->get_sfd(), &fd);
    select(data->get_sfd() + 1, &fd, nullptr, nullptr, &tv);
    if (FD_ISSET(data->get_sfd(), &fd))
      read_server(data->get_sfd());
    if (FD_ISSET(0, &fd))
      read_client(data);
  }
  return 0;
}
