/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "my_hunter.h"

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
	sfTexture *texture;
	sfSprite *sprite;
	sfEvent event;

	window = window_create(1280, 769);
	if (!window)
		return (84);
	texture = sfTexture_createFromFile("background.png", NULL);
	if (!texture)
		return (84);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_setFramerateLimit(window, 30);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_display(window);
	}
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
	sfRenderWindow_destroy(window);
	return (0);
}
