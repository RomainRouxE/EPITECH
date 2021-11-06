/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** display
*/

#include "client.h"

void vecValue(sfVector2f *vec, float x, float y)
{
	vec->x = x;
	vec->y = y;
}

void display_map(graph_t *graph, data_t *data)
{
	sfVector2f vec = {0, 0};

	for (int i = 0 ; data->map[i] != NULL ; ++i) {
		for (int j = 0 ; data->map[i][j] ; ++j) {
			vecValue(&vec, j * SIZE, i * SIZE);
			sfSprite_setPosition(graph->coin, vec);
			sfSprite_setPosition(graph->obstacle, vec);
			if (data->map[i][j] == 'e')
				sfRenderWindow_drawSprite(graph->window
				, graph->obstacle, NULL);
			else if (data->map[i][j] == 'c')
				sfRenderWindow_drawSprite(graph->window
				, graph->coin, NULL);
		}
	}
}

bool display_players(graph_t *graph, data_t *data)
{
	sfVector2f vec = {0, 0};

	sem_wait(&mutex);
	for (int i = 0 ; i < MAX_CLIENTS ; ++i) {
		if (data->player[0].y > strlen(data->map[0]))
			return false;
		vecValue(&vec, data->player[0].x * SIZE
		, data->player[0].y * SIZE);
		sfSprite_setPosition(graph->player, vec);
		sfRenderWindow_drawSprite(graph->window, graph->player, NULL);
	}
	sem_post(&mutex);
	return true;
}

void display_score(graph_t *graph, data_t *data)
{
	sfVector2f vec = {50, 50};
	char buffer[20];

	sem_wait(&mutex);
	snprintf(buffer, 20, "SCORE: %d", data->player[0].score);
	sem_post(&mutex);
	sfText_setString(graph->txt, buffer);
	sfText_setPosition(graph->txt, vec);
	sfText_setColor(graph->txt, sfYellow);
	sfRenderWindow_drawText(graph->window, graph->txt, NULL);
}

sfRenderWindow *create_window(data_t *data)
{
	sfVideoMode mode;
	sfRenderWindow *window;

	int i = 0;
	int j = 0;

	for ( ; data->map[i] != NULL ; ++i) {
		for ( ; data->map[i][j] ; ++j);
	}
	mode.width = j * SIZE;
	mode.height = i * SIZE;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "jetpack2Tek3"
	, sfResize | sfClose, NULL);
	if (window == NULL)
		return NULL;
	return window;
}
