/*
** EPITECH PROJECT, 2018
** zappy_ai
** File description:
** headerfile
*/

#ifndef ZAPPY_AI_HPP_
# define ZAPPY_AI_HPP_

#include <cstring>
#include <iostream>
#include <dlfcn.h>
#include "sfml.hpp"
#include "./SFML-2.4.2/include/SFML/Window.hpp"

#define LIBSFML_SYSTEM "./ai/include/SFML-2.4.2/lib/libsfml-system.so"
#define LIBSFML_AUDIO "./ai/include/SFML-2.4.2/lib/libsfml-audio.so"
#define LIBSFML_GRAPH "./ai/include/SFML-2.4.2/lib/libsfml-graphics.so"
#define LIBSFML_NET "./ai/include/SFML-2.4.2/lib/libsfml-network.so"
#define LIBSFML_WIN "./ai/include/SFML-2.4.2/lib/libsfml-window.so"

namespace ai
{
	class DLLoader{
	public:
		DLLoader(char *filename);
		~DLLoader();
		int entrypoint();
		create_t *create_triangle;
		create_video *create_videos;
		void *get_ptr();
		void launch_window();
	private:
		void *pointerlib;
		char *filename;
	};
};

int load_sfml(char *filename);

#endif /* ZAPPY_AI_HPP_ */
