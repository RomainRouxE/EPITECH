/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** move_players
*/

#include "server.h"

bool tile_action(list_t *list, struct timeval result, char *buffer, int i)
{
	if (list->map2[(int)list->player[i].y][(int)list->player[i].x] == 'c') {
		list->player[i].score += 1;
		list->map2[(int)list->player[i].y][(int)list->player[i].x]
		 = '_';
		sprintf(buffer, "COIN %d %d %d"
		, list->player[i].id, (int)list->player[i].y
		, (int)list->player[i].x);
		return false;
	}
	if (list->map2[(int)list->player[i].y][(int)list->player[i].x] == 'e'
	 || list->player[i].x > list->width) {
		sprintf(buffer, "FINISH -1");
		return false;
	}
	return true;
}

bool change_pos(list_t *list, struct timeval result, char *buffer, int sd)
{
	for (int i = 0 ; i < MAX_CLIENTS ; ++i) {
		if (!tile_action(list, result, buffer, i))
			return false;
		list->player[i].x = list->player[i].x
		 + (result.tv_usec * 1.0E-6) * 5;
		if (list->player[i].y < 0) {
			list->player[i].y = 0;
		} else if (list->player[i].y > list->height - 1) {
			list->player[i].y = list->height - 1;
		} else {
			if (list->player[i].jetpack)
				list->player[i].y = list->player[i].y
				 + result.tv_usec * 1.0E-6 * list->gravity * -1;
			else
				list->player[i].y = list->player[i].y
				 + result.tv_usec * 1.0E-6 * list->gravity;
		}
	}
	return true;
}

bool move_players(list_t *list, char *buffer , int sd)
{
	static struct timeval before = {0, 0};
	struct timeval after;
	struct timeval result;

	if (before.tv_sec == 0 && before.tv_usec == 0)
		gettimeofday(&before, NULL);
	gettimeofday(&after, NULL);
	timersub(&after, &before, &result);
	if (!change_pos(list, result, buffer, sd))
		return false;
	gettimeofday(&before, NULL);
	return true;
}

void fire_cmd(char *buffer, list_t *list, int sd)
{
	char *delimiter = strchr(buffer, ' ');
	int jetpack = atoi(delimiter);

	explicit_bzero(buffer, BUFFSIZE);
	for (int i = 0 ; i < MAX_CLIENTS ; ++i) {
		if (list->player[i].id == (unsigned)sd)
			list->player[i].jetpack = jetpack;
	}
	if (move_players(list, buffer, sd))
		sprintf(buffer, "PLAYER %d %f %f %d"
		, list->player[0].id, list->player[0].x
		, list->player[0].y, list->player[0].score);
}
