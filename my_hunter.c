/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include "include/my_hunter.h"

sfRenderWindow *window_create(unsigned int width,
			      unsigned int height)
{
	sfRenderWindow *window;
	sfVideoMode video_mode = {width, height, 32};

	window = sfRenderWindow_create(video_mode,
				       "Duck hunter",
				       sfClose,
				       NULL);
	return (window);
}

int main()
{
	sfRenderWindow *window;
	sfEvent event;

	window = window_create(800, 800);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, 30);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	return (0);
}
