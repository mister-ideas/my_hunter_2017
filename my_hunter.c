/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my_hunter.h"

sfRenderWindow *window_create(unsigned int width, unsigned int height)
{
	sfRenderWindow *window;
	sfVideoMode video_mode = {width, height, 32};

	window = sfRenderWindow_create(video_mode, "Duck hunt", sfClose, NULL);
	return (window);
}

int main()
{
	sfRenderWindow *window = window_create(1920, 1080);
	sfTexture *background_texture;
	sfTexture *pig_texture;
	sfSprite *background_sprite;
	sfSprite *pig_sprite;
	sfEvent event;
	sfIntRect rect;
	sfClock *clock = sfClock_create();
	sfTime time;
	float seconds;
	sfVector2f offset;
	sfVector2f position;

	offset.x = 10;
	offset.y = 0;
	rect.top = 0;
	rect.left = 0;
	rect.width = 80;
	rect.height = 80;
	if (!window)
		return (84);
	background_texture = sfTexture_createFromFile("background.png", NULL);
	if (!background_texture)
		return (84);
	pig_texture = sfTexture_createFromFile("spritesheet.png", NULL);
	if (!pig_texture)
		return (84);
	background_sprite = sfSprite_create();
	pig_sprite = sfSprite_create();
	sfSprite_setTexture(background_sprite, background_texture, sfTrue);
	sfSprite_setTexture(pig_sprite, pig_texture, sfTrue);
	sfRenderWindow_setFramerateLimit(window, 60);
	while (sfRenderWindow_isOpen(window)) {
		sfSprite_setTextureRect(pig_sprite, rect);
		position = sfSprite_getPosition(pig_sprite);
		if (position.x > 1840) {
			offset.x = rand() % 10 * -1;
			offset.y = rand() % 10;
		}
		if (position.x < 0) {
			offset.x = rand() % 10;
			offset.y = rand() % 10 * -1;
		}
		if (position.y < 0)
			offset.y = rand() % 10;
		if (position.y > 945)
			offset.y = rand() % 10 * -1;
		sfSprite_move(pig_sprite, offset);
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		if (seconds > 0.5) {
			if (rect.left != 480)
				rect.left += 80;
			else
				rect.left = 0;
			sfClock_restart(clock);
		}
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, background_sprite, NULL);
		sfRenderWindow_drawSprite(window, pig_sprite, NULL);
		sfRenderWindow_display(window);
	}
	sfTexture_destroy(background_texture);
	sfTexture_destroy(pig_texture);
	sfSprite_destroy(background_sprite);
	sfSprite_destroy(pig_sprite);
	sfRenderWindow_destroy(window);
	return (0);
}
