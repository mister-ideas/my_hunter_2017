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
	hunter->pig_pos = sfSprite_getPosition(hunter->pig_sprite);
	if (hunter->pig_pos.x > 1920) {
		if (hunter->lives - 1 == 0)
			sfRenderWindow_close(hunter->window);
		hunter->lives -= 1;
		if (hunter->lives == 2)
			sfSprite_setColor(hunter->bg_sprite, hunter->orange);
		if (hunter->lives == 1)
			sfSprite_setColor(hunter->bg_sprite, sfRed);
		hunter->pig_pos.x = 0;
		hunter->pig_pos.y = rand() % 960;
		sfSprite_setPosition(hunter->pig_sprite, hunter->pig_pos);
		hunter->offset.y = rand() % 10;
	}
	if (hunter->pig_pos.y > 960)
		hunter->offset.y = rand() % 10 * -1;
	if (hunter->pig_pos.y < 0)
		hunter->offset.y = rand() % 10;
}

void check_hit(hunter_t *hunter)
{
	hunter->mouse_pos = sfMouse_getPositionRenderWindow(hunter->window);
	if (hunter->mouse_pos.x > hunter->pig_pos.x
	&& hunter->mouse_pos.x < hunter->pig_pos.x + 80
	&& hunter->mouse_pos.y > hunter->pig_pos.y
	&& hunter->mouse_pos.y < hunter->pig_pos.y + 80) {
		hunter->score += 1;
		hunter->offset.x += 1;
		hunter->offset.y = rand() % 10;
		hunter->pig_pos.x = 0;
		hunter->pig_pos.y = rand() % 960;
		sfSprite_setPosition(hunter->pig_sprite, hunter->pig_pos);
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
