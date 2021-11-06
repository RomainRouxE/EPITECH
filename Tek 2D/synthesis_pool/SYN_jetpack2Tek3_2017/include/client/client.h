/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** client
*/

#pragma once

#define WIDTH 1920
#define HEIGHT 768
#define SIZE 20

#include "shared.h"

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Audio.h>

typedef struct opts {
	char *ip;
	unsigned port;
} opts_t;

typedef struct player {
	float x;
	float y;
	unsigned score;
} player_t;
typedef struct data {
	unsigned id;
	char **map;
	bool jetpack;
	player_t player[MAX_CLIENTS];
} data_t;

typedef struct graph {
	sfRenderWindow *window;
	sfEvent event;
	sfMusic* music;
	sfTexture *coinImg;
	sfTexture *obstacleImg;
	sfTexture *playerImg;
	sfSprite *coin;
	sfSprite *obstacle;
	sfSprite *player;
	sfVector2f vec;
	sfText *txt;
	sfFont *font;
} graph_t;

sem_t mutex;

opts_t store_opts(int ac, char **av);
int run_connection(opts_t opts);
void *init_graphics(void *data);
bool prefix(const char *pre, const char *str);
void move_player(data_t *data, char *reply);
void get_pos(int *x, int *y, char *reply);
void remove_coin(data_t *data, char *reply);
void display_map(graph_t *graph, data_t *data);
bool display_players(graph_t *graph, data_t *data);
void display_score(graph_t *graph, data_t *data);
sfRenderWindow *create_window(data_t *data);
void vecValue(sfVector2f *vec, float x, float y);
