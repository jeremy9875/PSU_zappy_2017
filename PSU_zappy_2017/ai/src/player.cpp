/*
** EPITECH PROJECT, 2018
** player
** File description:
** zappy
*/

#include "Player.hpp"
#include <unistd.h>
#include <cstring>

Player::Player()
{
	_fmap.insert(std::make_pair("Forward", &Player::mvForward));
	_fmap.insert(std::make_pair("Left", &Player::trLeft));
	_fmap.insert(std::make_pair("Right", &Player::trRight));
	_fmap.insert(std::make_pair("Look", &Player::Look));
	_fmap.insert(std::make_pair("Inv", &Player::getInv));
	_fmap.insert(std::make_pair("Broadcast", &Player::Broadcast));
	_fmap.insert(std::make_pair("TeamNb", &Player::getNumberSlotFree));
	_fmap.insert(std::make_pair("Fork", &Player::Fork));
	_fmap.insert(std::make_pair("Eject", &Player::Eject));
	_fmap.insert(std::make_pair("TakeObj", &Player::takeObj));
	_fmap.insert(std::make_pair("SetObj", &Player::dropObj));
	_fmap.insert(std::make_pair("Incantation", &Player::Incantation));
}

Player::~Player()
{
}

int Player::Call(const std::string &str)
{
	func fp = _fmap[str];
	return (this->*fp)();
}

std::string Player::_sendGet(std::string str)
{
	char buffer[1000];
	std::string tmp;

	dprintf(this->_sfd, "%s\n", str.c_str());
	int end = read(_sfd, buffer, 1000);
	str[end] = '\0';
	tmp = std::string(buffer);
/*	if (strlen(buffer) > 0)
		std::cout <<  tmp << "\n";*/
	return tmp;
}

bool Player::getNumberSlotFree()
{
	std::string str;

	str = _sendGet("Connect_nbr");
	_teamNb = std::stoi(str);

	return true;
}
bool Player::getInv()
{
	std::string str;
	std::string tmp;
	std::string::size_type pos;
	std::string::size_type tmp_pos;

	pos = 0;
	tmp_pos = 0;
	str = _sendGet("Inventory");
	while (str.size() != pos) {
		pos = str.find(',', pos);
		tmp = str.substr(tmp_pos, pos - 1);
		tmp_pos = pos;
		this->_inventory.push_back(tmp);
	}
	return true;
}

bool Player::takeObj()
{
	std::string str;

	str = _sendGet("Take object");
	if (str == "ko\n")
		return false;
	return true;
}

bool Player::dropObj()
{
	std::string str;

	str = _sendGet("Set object");
	if (str == "ko\n")
		return false;
	return true;
}

bool Player::mvForward()
{
	std::string str;

	str = _sendGet(FORWARD);
	if (str == "ko\n")
		return false;
	return true;
}

bool Player::trLeft()
{
	std::string str;

	str = _sendGet(LEFT);
	if (str == "ko\n")
		return false;
	return true;
}

bool Player::trRight()
{
	std::string str;

	str = _sendGet(RIGHT);
	if (str == "ko\n")
		return false;
	return true;
}

bool Player::Look()
{
	int nb_resource = 1;
	int pos = 0;
	std::string str;
	std::string tmp;

	str = _sendGet(LOOK);
	str = str.substr(1, str.size() - 3);
	for (size_t i = 0; i < str.size(); ++i)
		if (str[i] == ',')
			++nb_resource;
	for (int nb = 0; nb < nb_resource; ++nb) {
		tmp = str.substr(pos, str.find(',') - pos);
		this->_look.push_back(tmp);
		pos = str.find(',') + 1;
		str[str.find(',')] = '!';
//		std::cout << _look.back() << "\n";
	}
	return true;
}

bool Player::Broadcast()
{
	return true;
}

bool Player::Fork()
{
	return true;
}

bool Player::Eject()
{
	return true;
}

bool Player::setPlayer(std::string player, std::string pos)
{
//	this->_playerPos.push_back(std::stoi(pos));
	(void)pos;
	(void)player;	
//	this->_teamNb = std::stoi(player);
	return true;
}

bool Player::Incantation()
{
	return true;
}
