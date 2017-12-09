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

void set_target(hunter_t *hunter)
{
	hunter->mouse_pos = sfMouse_getPositionRenderWindow(hunter->window);
	hunter->mouse2_pos.x = (float)hunter->mouse_pos.x - 35;
	hunter->mouse2_pos.y = (float)hunter->mouse_pos.y - 35;
	sfSprite_setPosition(hunter->tg_sprite, hunter->mouse2_pos);
}

void game_loop(hunter_t *hunter)
{
	char score[12];

	check_borders(hunter);
	check_events(hunter);
	convert_score(score, hunter->score);
	set_target(hunter);
	set_score_text(score, hunter);
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
	window_display(hunter);
}

void game_free(hunter_t *hunter)
{
	sfTexture_destroy(hunter->bg_texture);
	sfTexture_destroy(hunter->pig_texture);
	sfSprite_destroy(hunter->bg_sprite);
	sfSprite_destroy(hunter->pig_sprite);
	sfText_destroy(hunter->score_text);
	sfFont_destroy(hunter->font);
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
