/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** tools.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my_hunter.h"

sfRenderWindow *window_create(unsigned int width, unsigned int height)
{
	sfRenderWindow *window;
	sfVideoMode video_mode = {width, height, 32};

	window = sfRenderWindow_create(video_mode, "Duck hunt", sfClose, NULL);
	return (window);
}

void game_free(hunter_t *hunter)
{
	sfTexture_destroy(hunter->bg_texture);
	sfTexture_destroy(hunter->pig_texture);
	sfSprite_destroy(hunter->bg_sprite);
	sfSprite_destroy(hunter->pig_sprite);
	sfRenderWindow_destroy(hunter->window);
}
