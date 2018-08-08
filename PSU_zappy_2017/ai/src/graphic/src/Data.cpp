/*
** EPITECH PROJECT, 2018
** Data
** File description
** zappy
*/

#include "connect.hpp"

Data::Data()
{
}

Data::~Data()
{
}

int Data::init(zappyWin *zappy)
{
  this->_zappy = zappy;
  this->tv.tv_sec = 10;
  this->tv.tv_usec = 0;
  this->set_name("guest");
  this->set_machine("graphic");
  if ((this->sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ||
      memset(&this->cliAddr, 0 ,sizeof(this->cliAddr)) == nullptr)
    return 84;
  this->cliAddr.sin_family = AF_INET;
  this->cliAddr.sin_addr.s_addr = inet_addr(this->ip.c_str());
  this->cliAddr.sin_port = htons(this->port);
  if (connect(this->sfd, (struct sockaddr *)&this->cliAddr,
	      sizeof(this->cliAddr)) < 0) {
    return 84;
  }
  return 0;
}

void Data::set_name(std::string name)
{
  this->name = name;
}

void Data::set_machine(std::string machine)
{
  this->machine = machine;
}

void Data::set_sfd(int sfd)
{
  this->sfd = sfd;
}

void Data::set_port(int port)
{
  this->port = port;
}

void Data::set_ip(std::string ip)
{
  this->ip = ip;
}

void Data::set_fd(fd_set fd)
{
  this->fd_read = fd;
}

void Data::set_sock(struct sockaddr_in socket)
{
  this->cliAddr = socket;
}

void Data::set_timev(struct timeval time)
{
  this->tv = time;
}

int Data::get_sfd(void)
{
  return (this->sfd);
}

fd_set Data::get_fdread(void)
{
  return (this->fd_read);
}

struct timeval Data::get_tv(void)
{
  return (this->tv);
}
