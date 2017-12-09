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
	hunter->best = 0;
	hunter->lives = 3;
	hunter->score_text_pos.x = 925;
	hunter->score_text_pos.y = 940;
	hunter->orange.r = 255;
	hunter->orange.g = 165;
	hunter->orange.b = 0;
	hunter->orange.a = 255;
	hunter->red.r = 255;
	hunter->red.g = 0;
	hunter->red.b = 0;
	hunter->red.a = 255;
}

int files_init(hunter_t *hunter)
{
	hunter->window = window_create(1920, 1080);
	if (!hunter->window)
		return (1);
	hunter->bg_texture = sfTexture_createFromFile(BG_PATH, NULL);
	if (!hunter->bg_texture)
		return (1);
	hunter->pig_texture = sfTexture_createFromFile(SPRITE_PATH, NULL);
	if (!hunter->pig_texture)
		return (1);
	hunter->tg_texture = sfTexture_createFromFile(TARGET_PATH, NULL);
	if (!hunter->tg_texture)
		return (1);
	hunter->font = sfFont_createFromFile(FONT_PATH);
	if (!hunter->font)
		return (1);
	return (0);
}

int game_init(hunter_t *hunter)
{
	if (files_init(hunter) == 1)
		return (1);
	val_init(hunter);
	hunter->score_text = sfText_create();
	hunter->bg_sprite = sfSprite_create();
	hunter->pig_sprite = sfSprite_create();
	hunter->tg_sprite = sfSprite_create();
	hunter->clock = sfClock_create();
	sfSprite_setTexture(hunter->bg_sprite, hunter->bg_texture, sfTrue);
	sfSprite_setTexture(hunter->pig_sprite, hunter->pig_texture, sfTrue);
	sfSprite_setTexture(hunter->tg_sprite, hunter->tg_texture, sfTrue);
	sfRenderWindow_setMouseCursorVisible(hunter->window, sfFalse);
	sfRenderWindow_setFramerateLimit(hunter->window, 60);
	return (0);
}
