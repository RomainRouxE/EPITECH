/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** server commands
*/

#include "server.h"

void id_cmd(char *buffer, int sd)
{
	sprintf(buffer, "ID %d", sd);
}

void map_cmd(char *buffer, list_t *list)
{
	sprintf(buffer, "%s", list->map);
	DEBUG("map");
}
void ready_cmd(char *buffer, list_t *list, int sd)
{
	sprintf(buffer, "NONE");
	for (int i = 0 ; i < MAX_CLIENTS ; ++i) {
		if (list->player[i].id == (unsigned)sd)
			list->player[i].ready = true;
		if (list->player[i].ready == false)
			return;
	}
	for (int i = 0 ; i < MAX_CLIENTS ; ++i) {
		if (send(list->player[i].id, "START\n", BUFFSIZE, 0)
		 != BUFFSIZE)
			perror("send");
	}
}

void coin_cmd(char *buffer, list_t *list)
{
	for (int i = 0 ; i < MAX_CLIENTS ; ++i) {
		if (send(list->player[i].id, buffer, BUFFSIZE, 0) != BUFFSIZE)
			perror("send:");
		explicit_bzero(buffer, BUFFSIZE);
	}
}

void do_command(char buffer[BUFFSIZE], list_t *list, int sd)
{
	if (prefix("ID", buffer)) {
		id_cmd(buffer, sd);
	} else if (prefix("MAP", buffer)) {
		map_cmd(buffer, list);
	} else if (prefix("READY", buffer)) {
		ready_cmd(buffer, list, sd);
	} else if (prefix("FIRE", buffer)) {
		fire_cmd(buffer, list, sd);
	} else {
		DEBUG("Unkown command");
	}
}
