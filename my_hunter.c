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
	hunter->position = sfSprite_getPosition(hunter->pig_sprite);
	if (hunter->position.x > 1840) {
		hunter->offset.x = rand() % 10 * -1;
		hunter->offset.y = rand() % 10;
	}
	if (hunter->position.x < 0) {
		hunter->offset.x = rand() % 10;
		hunter->offset.y = rand() % 10 * -1;
	}
	if (hunter->position.y < 0)
		hunter->offset.y = rand() % 10;
	if (hunter->position.y > 945)
		hunter->offset.y = rand() % 10 * -1;
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

void game_init(hunter_t *hunter)
{
	hunter->window = window_create(1920, 1080);
	hunter->clock = sfClock_create();
	hunter->offset.x = 10;
	hunter->offset.y = 0;
	hunter->rect.top = 0;
	hunter->rect.left = 0;
	hunter->rect.width = 80;
	hunter->rect.height = 80;
	if (!hunter->window)
		exit(84);
	hunter->bg_texture = sfTexture_createFromFile("background.png", NULL);
	if (!hunter->bg_texture)
		exit(84);
	hunter->pig_texture = sfTexture_createFromFile("spritesheet.png", NULL);
	if (!hunter->pig_texture)
		exit(84);
	hunter->bg_sprite = sfSprite_create();
	hunter->pig_sprite = sfSprite_create();
	sfSprite_setTexture(hunter->bg_sprite, hunter->bg_texture, sfTrue);
	sfSprite_setTexture(hunter->pig_sprite, hunter->pig_texture, sfTrue);
}

int main()
{
	hunter_t hunter;

	game_init(&hunter);
	sfRenderWindow_setFramerateLimit(hunter.window, 60);
	while (sfRenderWindow_isOpen(hunter.window))
		game_loop(&hunter);
	game_free(&hunter);
	return (0);
}
