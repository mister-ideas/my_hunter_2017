/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** text.c
*/

#include <SFML/Graphics.h>
#include "my_hunter.h"
#include "my.h"

void set_score_text(char score[], hunter_t *hunter)
{
	sfText_setString(hunter->score_text, score);
	sfText_setFont(hunter->score_text, hunter->font);
	sfText_setCharacterSize(hunter->score_text, 70);
	sfText_setPosition(hunter->score_text, hunter->score_text_pos);
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
