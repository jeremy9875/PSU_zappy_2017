/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils.c
*/

#include "zappy_server.h"
#include "define_server.h"

int len_param(char *_src, int _begin)
{
	int _len = 0;

	while (_src[_begin] != '\n') {
		_begin += 1;
		_len += 1;
	}
	return _len + 1;
}

char *treat_line(char *_src, int _begin)
{
	char *_buffer;
	int _countSrc = _begin + 1;
	int _countBuffer = 0;
	int _len = strlen(_src);

	if (_len <= (_begin + 1))
		return NULL;
	if ((_buffer = malloc(sizeof(char) * len_param(_src, _begin))) == NULL)
		return NULL;
	while (_src[_countSrc] != '\n') {
		_buffer[_countBuffer] = _src[_countSrc];
		_countBuffer += 1;
		_countSrc += 1;
	}
	_buffer[_countBuffer] = '\0';
	return _buffer;
}
