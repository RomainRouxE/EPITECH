/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** graphics
*/

#include "client.h"

void jetpack(data_t *data)
{
	data->jetpack = sfKeyboard_isKeyPressed(sfKeySpace) ? true : false;
}

graph_t init_graph(data_t *data)
{
	graph_t graph;
	sfVector2f vec = {0, 0};

	graph.window = create_window(data);
	graph.music = sfMusic_createFromFile("media/music.ogg");
	graph.coinImg = sfTexture_createFromFile("media/coin.png", NULL);
	graph.obstacleImg = sfTexture_createFromFile("media/box.png", NULL);
	graph.playerImg = sfTexture_createFromFile("media/character.png", NULL);
	graph.coin = sfSprite_create();
	graph.obstacle = sfSprite_create();
	graph.player = sfSprite_create();
	graph.txt = sfText_create();
	graph.font = sfFont_createFromFile("media/SuperMario256.ttf");
	sfMusic_play(graph.music);
	sfText_setFont(graph.txt, graph.font);
	sfText_setCharacterSize(graph.txt, 50);
	sfSprite_setTexture(graph.coin, graph.coinImg, sfTrue);
	sfSprite_setTexture(graph.obstacle, graph.obstacleImg, sfTrue);
	sfSprite_setTexture(graph.player, graph.playerImg, sfTrue);
	sfSprite_setPosition(graph.player, vec);
	return graph;
}

void destroy_graph(graph_t *graph)
{
	sfRenderWindow_clear(graph->window, sfWhite);
	sfSprite_destroy(graph->coin);
	sfSprite_destroy(graph->obstacle);
	sfSprite_destroy(graph->player);
	sfTexture_destroy(graph->coinImg);
	sfTexture_destroy(graph->obstacleImg);
	sfTexture_destroy(graph->playerImg);
	sfMusic_destroy(graph->music);
}

void render_winder(graph_t *graph, data_t *data)
{
	sfEvent event;
	
	while (sfRenderWindow_isOpen(graph->window)) {
		while (sfRenderWindow_pollEvent(graph->window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(graph->window);
		}
		jetpack(data);
		display_map(graph, data);
		display_score(graph, data);
		if (!display_players(graph, data)) {
			sfRenderWindow_close(graph->window);
			break;
		}
		sfRenderWindow_display(graph->window);
		sfRenderWindow_clear(graph->window, sfWhite);
	}
}

void *init_graphics(void *ptr)
{
	data_t *data = (data_t *)ptr;
	graph_t graph = init_graph(data);

	render_winder(&graph, data);
	destroy_graph(&graph);
	return NULL;
}
