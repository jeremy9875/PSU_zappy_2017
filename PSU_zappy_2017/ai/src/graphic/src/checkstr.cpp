/*
** EPITECH PROJECT, 2018
** checkstr
** File description
** zappy
*/

#include "connect.hpp"

bool checkstr(std::string str)
{
  bool has_only_digits = (str.find_first_not_of( "0123456789." ) == std::string::npos);
  if (has_only_digits == true)
    return true;
  else
    return false;
  return true;
}
