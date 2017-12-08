/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my_hunter.h"

void game_free(hunter_t *hunter)
{
	sfTexture_destroy(hunter->bg_texture);
	sfTexture_destroy(hunter->pig_texture);
	sfSprite_destroy(hunter->bg_sprite);
	sfSprite_destroy(hunter->pig_sprite);
	sfRenderWindow_destroy(hunter->window);
}

int main(void)
{
	hunter_t hunter;

	if (game_init(&hunter) == 1)
		return (84);
	while (sfRenderWindow_isOpen(hunter.window))
		game_loop(&hunter);
	game_free(&hunter);
	return (0);
}
