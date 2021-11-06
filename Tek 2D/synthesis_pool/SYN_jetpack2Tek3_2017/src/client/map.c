/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** map
*/

#include "client.h"

void get_pos_score(float *x, float *y, int *score, char *reply)
{
	char *delimiter = NULL;

	delimiter = strchr(reply, ' ');
	delimiter = strchr(++delimiter, ' ');
	*x = atof(strtok(delimiter, " "));
	delimiter = strchr(++delimiter, ' ');
	*y = atof(strtok(delimiter, " "));
	*score = atoi(strtok(delimiter, " "));
}

void move_player(data_t *data, char *reply)
{
	float x = 0;
	float y = 0;
	int score = 0;

	get_pos_score(&x, &y, &score, reply);
	sem_wait(&mutex);
	for (int i = 0 ; i < MAX_CLIENTS ; ++i) {
		data->player[i].x = x;
		data->player[i].y = y;
		data->player[i].score = score;
		DEBUG(":::::: %f %f :::::::", data->player[i].x
		, data->player[i].y);
	}
	sem_post(&mutex);
}

void get_pos(int *x, int *y, char *reply)
{
	char *delimiter = NULL;

	DEBUG(":: %s", reply);
	delimiter = strchr(reply, ' ');
	delimiter = strchr(++delimiter, ' ');
	*x = atoi(strtok(delimiter, " "));
	DEBUG("delim: %s", delimiter);
	delimiter = strchr(++delimiter, ' ');
	*y = atoi(strtok(delimiter, " "));
}

void remove_coin(data_t *data, char *reply)
{
	int x = 0;
	int y = 0;
	int score = 0;

	get_pos(&x, &y, reply);
	sem_wait(&mutex);
	for (int i = 0 ; i < MAX_CLIENTS ; ++i)
		data->map[x][y] = '_';
	sem_post(&mutex);
}
