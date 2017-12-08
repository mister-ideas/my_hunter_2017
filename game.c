/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** game.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my_hunter.h"

void check_borders(hunter_t *hunter)
{
	hunter->pig_position = sfSprite_getPosition(hunter->pig_sprite);
	if (hunter->pig_position.x > 1920) {
		if (hunter->lives - 1 == 0)
			sfRenderWindow_close(hunter->window);
		else
			hunter->lives -= 1;
		hunter->pig_position.x = 0;
		hunter->pig_position.y = rand() % 960;
		sfSprite_setPosition(hunter->pig_sprite, hunter->pig_position);
		hunter->offset.y = rand() % 5;
	}
	if (hunter->pig_position.y > 960)
		hunter->offset.y = rand() % 5 * -1;
	if (hunter->pig_position.y < 0)
		hunter->offset.y = rand() % 5;
}

void check_hit(hunter_t *hunter)
{
	hunter->mouse_position = sfMouse_getPositionRenderWindow(hunter->window);
	if (hunter->mouse_position.x > hunter->pig_position.x
	&& hunter->mouse_position.x < hunter->pig_position.x + 80
	&& hunter->mouse_position.y > hunter->pig_position.y
	&& hunter->mouse_position.y < hunter->pig_position.y + 80) {
		hunter->score += 1;
		hunter->offset.x += 1;
		hunter->offset.y = rand() % 5;
		hunter->pig_position.x = 0;
		hunter->pig_position.y = rand() % 960;
		sfSprite_setPosition(hunter->pig_sprite, hunter->pig_position);
	}
}

void check_events(hunter_t *hunter)
{
	while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
		if (hunter->event.type == sfEvtClosed)
			sfRenderWindow_close(hunter->window);
		if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
			check_hit(hunter);
	}
}

void game_loop(hunter_t *hunter)
{
	check_borders(hunter);
	check_events(hunter);
	sfSprite_setTextureRect(hunter->pig_sprite, hunter->rect);
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
	sfRenderWindow_clear(hunter->window, sfBlack);
	sfRenderWindow_drawSprite(hunter->window, hunter->bg_sprite, NULL);
	sfRenderWindow_drawSprite(hunter->window, hunter->pig_sprite, NULL);
	sfRenderWindow_display(hunter->window);
}
