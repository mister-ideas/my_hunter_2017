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

void check_borders(hunter_t *hunter)
{
	hunter->pig_position = sfSprite_getPosition(hunter->pig_sprite);
	if (hunter->pig_position.x > 1920) {
		hunter->offset.x += 1;
		hunter->pig_position.x = 0;
		hunter->pig_position.y = rand() % 960;
		sfSprite_setPosition(hunter->pig_sprite, hunter->pig_position);
	}
}

void game_loop(hunter_t *hunter)
{
	sfSprite_setTextureRect(hunter->pig_sprite, hunter->rect);
	check_borders(hunter);
	sfSprite_move(hunter->pig_sprite, hunter->offset);
	hunter->time = sfClock_getElapsedTime(hunter->clock);
	hunter->seconds = hunter->time.microseconds / 1000000.0;
	if (hunter->seconds > 0.5) {
		if (hunter->rect.left != 480)
			hunter->rect.left += 80;
		else
			hunter->rect.left = 0;
		sfClock_restart(hunter->clock);
	}
	while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
		if (hunter->event.type == sfEvtClosed)
			sfRenderWindow_close(hunter->window);
	}
	sfRenderWindow_clear(hunter->window, sfBlack);
	sfRenderWindow_drawSprite(hunter->window, hunter->bg_sprite, NULL);
	sfRenderWindow_drawSprite(hunter->window, hunter->pig_sprite, NULL);
	sfRenderWindow_display(hunter->window);
}

int game_init(hunter_t *hunter)
{
	hunter->clock = sfClock_create();
	hunter->offset.x = 10;
	hunter->offset.y = 0;
	hunter->rect.top = 0;
	hunter->rect.left = 0;
	hunter->rect.width = 80;
	hunter->rect.height = 80;
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
	sfSprite_setTexture(hunter->bg_sprite, hunter->bg_texture, sfTrue);
	sfSprite_setTexture(hunter->pig_sprite, hunter->pig_texture, sfTrue);
	return (0);
}

int main(void)
{
	hunter_t hunter;

	hunter.window = window_create(1920, 1080);
	if (game_init(&hunter) == 1)
		return (84);
	sfRenderWindow_setFramerateLimit(hunter.window, 60);
	while (sfRenderWindow_isOpen(hunter.window))
		game_loop(&hunter);
	game_free(&hunter);
	return (0);
}
