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
#define TARGET_PATH "ressources/img/target.png"
#define FONT_PATH "ressources/fonts/XpressiveRegular.ttf"

typedef struct hunter_t {
	sfRenderWindow *window;
	sfTexture *bg_texture;
	sfTexture *pig_texture;
	sfTexture *tg_texture;
	sfSprite *bg_sprite;
	sfSprite *pig_sprite;
	sfSprite *tg_sprite;
	sfText *score_text;
	sfText *best_text;
	sfFont *font;
	sfEvent event;
	sfIntRect rect;
	sfClock *clock;
	sfTime time;
	float seconds;
	sfVector2f offset;
	sfVector2f pig_pos;
	sfVector2f score_text_pos;
	sfVector2i mouse_pos;
	sfVector2f mouse2_pos;
	int score;
	int best;
	int lives;
	sfColor orange;
	sfColor red;
} hunter_t;

sfRenderWindow *window_create(unsigned int width, unsigned int height);

void check_borders(hunter_t *hunter);
void check_hit(hunter_t *hunter);
void check_events(hunter_t *hunter);
void game_loop(hunter_t *hunter);
void game_free(hunter_t *hunter);
void val_init(hunter_t *hunter);
void convert_score(char str[], int num);
void finished_text(hunter_t *hunter);
void closed_text(void);
void reset_pig(hunter_t *hunter);
void set_score_text(char score[], hunter_t *hunter);
void window_display(hunter_t *hunter);
void set_target(hunter_t *hunter);

int game_init(hunter_t *hunter);
int files_init(hunter_t *hunter);

#endif
