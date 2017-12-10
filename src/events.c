/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** game.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_hunter.h"
#include "my.h"

void reset_pig(hunter_t *hunter)
{
	if (hunter->lives == 2) {
		sfSprite_setColor(hunter->bg_sprite, hunter->orange);
		sfSprite_setColor(hunter->tg_sprite, hunter->orange);
		sfText_setColor(hunter->score_text, hunter->orange);
	}
	if (hunter->lives == 1) {
		sfSprite_setColor(hunter->bg_sprite, hunter->red);
		sfSprite_setColor(hunter->tg_sprite, hunter->red);
		sfText_setColor(hunter->score_text, hunter->red);
	}
	hunter->pig_pos.x = 0;
	hunter->pig_pos.y = rand() % 960;
	sfSprite_setPosition(hunter->pig_sprite, hunter->pig_pos);
	hunter->offset.y = rand() % 10;
}

void check_borders(hunter_t *hunter)
{
	hunter->pig_pos = sfSprite_getPosition(hunter->pig_sprite);
	if (hunter->pig_pos.x > 1920) {
		if (hunter->lives - 1 == 0) {
			sfRenderWindow_close(hunter->window);
			finished_text(hunter);
		}
		hunter->lives -= 1;
		reset_pig(hunter);
	}
	if (hunter->pig_pos.y > 960)
		hunter->offset.y = rand() % 10 * -1;
	if (hunter->pig_pos.y < 0)
		hunter->offset.y = rand() % 10;
}

void check_hit(hunter_t *hunter)
{
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
		if (hunter->event.type == sfEvtClosed
		|| (hunter->event.type == sfEvtKeyPressed
		&& hunter->event.key.code == sfKeyEscape)) {
			sfRenderWindow_close(hunter->window);
			closed_text();
		}
		if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
			check_hit(hunter);
	}
}
