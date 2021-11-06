/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** server
*/

#include "server.h"

server_t init_struct()
{
	server_t se;

	se.opt = true;
	se.max_clients = MAX_CLIENTS;
	return se;
}

void do_socket(server_t *se, opts_t opts)
{
	for (int i = 0 ; i < se->max_clients; ++i)
		se->client_socket[i] = 0;
	if ((se->master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	if (setsockopt(se->master_socket, SOL_SOCKET, SO_REUSEADDR
	, (char *)&se->opt, sizeof(se->opt)) < 0) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	se->address.sin_family = AF_INET;
	se->address.sin_addr.s_addr = INADDR_ANY;
	se->address.sin_port = htons(opts.port);
}

void do_bind(server_t *se)
{
	if (bind(se->master_socket
	, (struct sockaddr *)&se->address, sizeof(se->address)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
}

void do_listen(server_t *se, opts_t opts)
{
	if (listen(se->master_socket, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	se->addrlen = sizeof(se->address);
}

void add_to_set(server_t *se)
{
	FD_ZERO(&se->readfds);
	FD_SET(se->master_socket, &se->readfds);
	se->max_sd = se->master_socket;
	for (int i = 0 ; i < se->max_clients ; ++i) {
		se->sd = se->client_socket[i];
		if (se->sd > 0)
			FD_SET(se->sd, &se->readfds);
		if (se->sd > se->max_sd)
			se->max_sd = se->sd;
	}
}

void do_select(server_t *se)
{
	se->activity = select(se->max_sd + 1, &se->readfds, NULL, NULL, NULL);
	if ((se->activity < 0) && (errno != EINTR))
		PRINT_ERR("select error");
}

void add_player(int new_socket, list_t *list)
{
	for (int i = 0 ; i < MAX_CLIENTS ; ++i)
		if (list->player[i].id == 0) {
			list->player[i].id = new_socket;
			return;
		}
}

void do_accept(server_t *se, list_t *list)
{
	if (FD_ISSET(se->master_socket, &se->readfds)) {
		if ((se->new_socket = accept(se->master_socket
		, (struct sockaddr *)&se->address
		, (socklen_t *)&se->addrlen)) < 0) {
			perror("accept");
			exit(EXIT_FAILURE);
		}
		add_player(se->new_socket, list);
		for (int i = 0 ; i < se->max_clients; ++i) {
			if (se->client_socket[i] == 0) {
				se->client_socket[i] = se->new_socket;
				break;
			}
		}
	}
}

void other_socket(server_t *se, list_t *list)
{
	for (int i = 0; i < se->max_clients; ++i) {
		se->sd = se->client_socket[i];
		if (FD_ISSET(se->sd, &se->readfds)) {
			if ((se->valread = read(se->sd, se->buffer
			, BUFFSIZE)) == 0) {
				getpeername(se->sd
				, (struct sockaddr *)&se->address
				, (socklen_t *)&se->addrlen);
				close(se->sd);
				se->client_socket[i] = 0;
			} else {
				se->buffer[se->valread] = '\0';
				do_command(se->buffer, list, se->sd);
				if (strcmp(se->buffer, "NONE")) {
					if (send(se->sd, se->buffer
					, BUFFSIZE, 0) != BUFFSIZE)
						perror("send");
				}
				explicit_bzero(se->buffer, BUFFSIZE);
			}	
		}
	}
}

int run_server(opts_t opts, list_t list)
{
	server_t se = init_struct();
	
	do_socket(&se, opts);
	do_bind(&se);
	do_listen(&se, opts);
	while (true) {
		add_to_set(&se);
		do_select(&se);
		do_accept(&se, &list);
		other_socket(&se, &list);
	}
	return SUCCESS;
}
