/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** text.c
*/

#include <SFML/Graphics.h>
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

void set_score_text(char score[], hunter_t *hunter)
{
	sfText_setString(hunter->score_text, score);
	sfText_setFont(hunter->score_text, hunter->font);
	sfText_setCharacterSize(hunter->score_text, 70);
	sfText_setPosition(hunter->score_text, hunter->score_text_pos);
}

void window_display(hunter_t *hunter)
{
	sfRenderWindow_clear(hunter->window, sfBlack);
	sfRenderWindow_drawSprite(hunter->window, hunter->bg_sprite, NULL);
	sfRenderWindow_drawText(hunter->window, hunter->score_text, NULL);
	sfRenderWindow_drawSprite(hunter->window, hunter->pig_sprite, NULL);
	sfRenderWindow_drawSprite(hunter->window, hunter->tg_sprite, NULL);
	sfRenderWindow_display(hunter->window);
}

void finished_text(hunter_t *hunter)
{
	my_putstr("====================\n");
	my_putstr("Final score: ");
	my_put_nbr(hunter->score);
	my_putchar('\n');
	my_putstr("Best score: ");
	my_put_nbr(hunter->best);
	my_putchar('\n');
	my_putstr("====================\n");
}

void closed_text(void)
{
	my_putstr("====================\n");
	my_putstr("You left the game!");
	my_putchar('\n');
	my_putstr("====================\n");
}
