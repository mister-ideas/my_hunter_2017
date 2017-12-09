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
#include "my.h"

void convert_score(char str[], int num)
{
	int i;
	int rem;
	int len = 0;
	int n;

	n = num;
	while (n) {
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++) {
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}

void reset_pig(hunter_t *hunter)
{
	if (hunter->lives == 2) {
		sfSprite_setColor(hunter->bg_sprite, hunter->orange);
		sfSprite_setColor(hunter->target_sprite, hunter->orange);
		sfText_setColor(hunter->score_text, hunter->orange);
	}
	if (hunter->lives == 1) {
		sfSprite_setColor(hunter->bg_sprite, hunter->red);
		sfSprite_setColor(hunter->target_sprite, hunter->red);
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

void display(hunter_t *hunter)
{
	sfRenderWindow_clear(hunter->window, sfBlack);
	sfRenderWindow_drawSprite(hunter->window, hunter->bg_sprite, NULL);
	sfRenderWindow_drawText(hunter->window, hunter->score_text, NULL);
	sfRenderWindow_drawSprite(hunter->window, hunter->pig_sprite, NULL);
	sfRenderWindow_drawSprite(hunter->window, hunter->target_sprite, NULL);
	sfRenderWindow_display(hunter->window);
}

void game_loop(hunter_t *hunter)
{
	char score[12];

	check_borders(hunter);
	check_events(hunter);
	convert_score(score, hunter->score);
	hunter->mouse_pos = sfMouse_getPositionRenderWindow(hunter->window);
	hunter->mouse2_pos.x = (float)hunter->mouse_pos.x - 35;
	hunter->mouse2_pos.y = (float)hunter->mouse_pos.y - 35;
	sfSprite_setPosition(hunter->target_sprite, hunter->mouse2_pos);
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
	display(hunter);
}
