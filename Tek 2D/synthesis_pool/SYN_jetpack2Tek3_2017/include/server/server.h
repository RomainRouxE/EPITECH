/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** server
*/

#pragma once

#include "shared.h"

typedef struct opts {
	unsigned port;
	unsigned gravity;
	char *map;
} opts_t;

typedef struct server {
	int opt;
	int master_socket;
	int addrlen;
	int new_socket;
	int client_socket[MAX_CLIENTS];
	int max_clients;
	int activity;
	int valread;
	int sd;
	int max_sd;
	struct sockaddr_in address;
	char buffer[BUFFSIZE];
	fd_set readfds;
	char *message;
} server_t;

typedef struct player {
	unsigned id;
	float x;
	float y;
	unsigned score;
	bool jetpack;
	bool ready;
} player_t;

typedef struct list {
	unsigned height;
	unsigned width;
	unsigned gravity;
	char map[BUFFSIZE];
	char **map2;
	player_t player[MAX_CLIENTS];
} list_t;

opts_t store_opts(int ac, char **av);
int run_server(opts_t opts, list_t list);
void do_command(char buffer[BUFFSIZE], list_t *list, int sd);
void fire_cmd(char *buffer, list_t *list, int sd);
bool prefix(const char *pre, const char *str);
