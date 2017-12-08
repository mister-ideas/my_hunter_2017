/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#define BG_PATH "ressources/img/background.png"
#define SPRITE_PATH "ressources/img/spritesheet.png"
#define FONT_PATH "ressources/fonts/XpressiveRegular.ttf"

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
	sfVector2f pig_pos;
	sfVector2i mouse_pos;
	int score;
	int lives;
} hunter_t;

sfRenderWindow *window_create(unsigned int width, unsigned int height);

void check_borders(hunter_t *hunter);
void check_hit(hunter_t *hunter);
void game_loop(hunter_t *hunter);
void game_free(hunter_t *hunter);

int game_init(hunter_t *hunter);

#endif
