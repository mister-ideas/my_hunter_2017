/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

typedef struct hunter {
	sfRenderWindow *window;
	sfTexture *bg_texture;
	sfTexture *pig_texture;
	sfSprite *bg_sprite;
	sfSprite *pig_sprite;
	sfEvent event;
	sfIntRect rect;
	sfClock *clock;
	sfTime time;
	float seconds;
	sfVector2f offset;
	sfVector2f position;
} hunter_t;

sfRenderWindow *window_create(unsigned int width, unsigned int height);

void check_borders(hunter_t *hunter);
void game_loop(hunter_t *hunter);
void game_init(hunter_t *hunter);
void game_free(hunter_t *hunter);

#endif
