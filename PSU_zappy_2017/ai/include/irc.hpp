/*
** EPITECH PROJECT, 2018
** IRC.hpp
** File description:
** IRC.hpp
*/

#include "map.hpp"

#ifndef IRC_HPP_
# define IRC_HPP_

# define OK 0
# define ERROR 84

char *treat_line(char *, int);
char *take_name(char *, int);
char *take_msg(char *, int);
int get_msz(std::string);
int get_bct(std::string);
int get_mct(std::string);
int getTna(std::string);
int getPex(std::string);
int getPfk(std::string);
int getPdi(std::string);
int getPbc(std::string);
int getPdr(std::string);
int getPgt(std::string);
int getEht(std::string);
int getEbo(std::string);
int getPlv(std::string);
int getSmg(std::string);
int getSeg(std::string);
int getEdi(std::string);
int getSgt(std::string);
int getSst(std::string);
int getPpo(std::string);
int getPin(std::string);
int getPie(std::string);
int getEnw(std::string);

#endif /* !IRC_HPP_ */
