/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** init.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my_hunter.h"

sfRenderWindow *window_create(unsigned int width, unsigned int height)
{
	sfRenderWindow *window;
	sfVideoMode video_mode = {width, height, 32};

	window = sfRenderWindow_create(video_mode, "Pig Hunter", sfClose, NULL);
	return (window);
}

void val_init(hunter_t *hunter)
{
	hunter->offset.x = 10;
	hunter->offset.y = 0;
	hunter->rect.top = 0;
	hunter->rect.left = 0;
	hunter->rect.width = 80;
	hunter->rect.height = 80;
	hunter->score = 0;
	hunter->lives = 3;
}

int game_init(hunter_t *hunter)
{
	val_init(hunter);
	hunter->window = window_create(1920, 1080);
	if (!hunter->window)
		return (1);
	hunter->bg_texture = sfTexture_createFromFile(BG_PATH, NULL);
	if (!hunter->bg_texture)
		return (1);
	hunter->pig_texture = sfTexture_createFromFile(SPRITE_PATH, NULL);
	if (!hunter->pig_texture)
		return (1);
	hunter->bg_sprite = sfSprite_create();
	hunter->pig_sprite = sfSprite_create();
	hunter->clock = sfClock_create();
	sfSprite_setTexture(hunter->bg_sprite, hunter->bg_texture, sfTrue);
	sfSprite_setTexture(hunter->pig_sprite, hunter->pig_texture, sfTrue);
	sfRenderWindow_setFramerateLimit(hunter->window, 60);
	return (0);
}
