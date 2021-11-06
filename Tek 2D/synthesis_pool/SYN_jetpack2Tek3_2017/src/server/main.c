/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** server main
*/

#include "server.h"

void prepend(char* s, const char* t)
{
	size_t len = strlen(t);

	memmove(s + len, s, strlen(s) + 1);
	for (size_t i = 0; i < len; ++i)
		s[i] = t[i];
}

bool store_map(char *map, list_t *list)
{
	FILE *fp = fopen(map, "r");
	char *line = NULL;
	char pre[30];
	ssize_t read;
	ssize_t tmp;
	size_t len = 0;
	int i = 0;

	if (fp == NULL) {
		PRINT_ERR("Cannot open file");
		return false;
	}
	while ((read = getline(&line, &len, fp)) != -1) {
		tmp = read;
		line[read - 1] = '\0';
		strcat(list->map, line);
		++i;
	}
	rewind(fp);
	list->map2 = malloc(sizeof(char *) * i);
	i = 0;
	while ((read = getline(&line, &len, fp)) != -1) {
		list->map2[i] = malloc(sizeof(char) * read);
		strcpy(list->map2[i++], line);
	}
	for (int j = 0 ; j < i ; ++j)
		DEBUG("map2: %s", list->map2[j]);
	list->height = i;
	list->width = tmp;
	for (int j = 0 ; j < MAX_CLIENTS ; ++j) {
		list->player[j].x = 0;
		list->player[j].y = i / 2;
	}
	sprintf(pre, "%zd %d ", tmp, i);
	prepend(list->map, pre);
	fclose(fp);
	return true;
}

list_t init_players(opts_t *opts)
{
	list_t list;

	explicit_bzero(list.map, BUFFSIZE);
	for (int i = 0 ; i < MAX_CLIENTS ; ++i) {
		list.player[i].id = 0;
		list.player[i].score = 0;
		list.player[i].jetpack = false;
		list.player[i].ready = false;
	}
	list.gravity = opts->gravity;
	return list;
}

int main(int ac, char **av)
{
	opts_t opts = store_opts(ac, av);
	list_t list = init_players(&opts);

	if (!store_map(opts.map, &list))
		return FAILURE;
	run_server(opts, list);
	return SUCCESS;
}
