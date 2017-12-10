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
	my_putstr("====================\n");
}

void closed_text(void)
{
	my_putstr("====================\n");
	my_putstr("You left the game!");
	my_putchar('\n');
	my_putstr("====================\n");
}

void help_text(void)
{
	my_putstr("====================\n");
	my_putstr("Pig Hunter\n");
	my_putstr("====================\n\n");
	my_putstr("USAGE\n");
	my_putstr("    	./my_hunter [OPTIONS]\n\n");
	my_putstr("OPTIONS\n");
	my_putstr("    	-h	Print usage and exit.\n\n");
	my_putstr("Note: Don't forget to read the 'README' file for rules and more!\n");
}
