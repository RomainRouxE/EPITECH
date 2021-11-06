/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** server
*/

#include "client.h"

bool send_recv(int sock, char *buffer, char *reply)
{
	if (send(sock, buffer , BUFFSIZE, 0) < 0) {
		PRINT_ERR("Send failed");
		return false;
	}
	if (recv(sock, reply , BUFFSIZE, 0) < 0) {
		PRINT_ERR("recv failed");
		return false;
	}
	return true;
}

void store_map(char *reply, data_t *data)
{
	int width = 0;
	int height = 0;
	char str[BUFFSIZE];

	sscanf(reply, "%d %d %s", &width, &height, str);
	data->map = malloc(sizeof(char *) * height);
	for (int i = 0 ; i < height ; ++i) {
		data->map[i] = malloc(sizeof(char) * width);
		snprintf(data->map[i], width, "%s", str);
		strcpy(str, str + width - 1);
	}
	data->map[height] = NULL;
}

void add_graphics(data_t *data)
{
	pthread_t handle;

	if(pthread_create(&handle, NULL, init_graphics, (void *)data)) {
		PRINT_ERR("cannot create thread");
		exit(FAILURE);
	}
}

void prepare(int sock, char *buffer, char *reply, data_t *data)
{
	char *delimiter;

	strcpy(buffer, "ID\n");
	if (!send_recv(sock, buffer, reply)) {
		PRINT_ERR("Cannot get id");
		exit(FAILURE);
	}
	delimiter = strchr(reply, ' ');
	data->id = atoi(++delimiter);
	strcpy(buffer, "MAP\n");
	if (!send_recv(sock, buffer, reply)) {
		PRINT_ERR("Cannot get map");
		exit(FAILURE);
	}
	store_map(reply, data);

	add_graphics(data);
	strcpy(buffer, "READY\n");
	if (!send_recv(sock, buffer, reply)) {
		PRINT_ERR("Cannot send ready");
		exit(FAILURE);
	}
	if (strcmp(reply, "START\n")) {
		PRINT_ERR("Wrong command: %s", reply);
		exit(FAILURE);
	}
}

int run_connection(opts_t opts)
{
	int sock = socket(AF_INET , SOCK_STREAM , 0);
	struct sockaddr_in server;
	char buffer[BUFFSIZE];
	char reply[BUFFSIZE];
	data_t *data = malloc(sizeof(data_t));

	if (sock == -1)
		PRINT_ERR("Could not create socket");
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(opts.port);
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
		perror("connect failed. Error");
		return FAILURE;
	}
	explicit_bzero(buffer, BUFFSIZE);
	prepare(sock, buffer, reply, data);
	while (true) {
		sprintf(buffer, "FIRE %d", data->jetpack);
		if (!send_recv(sock, buffer, reply))
			break;
		if (prefix("PLAYER", reply))
			move_player(data, reply);
		if (prefix("COIN", reply))
			remove_coin(data, reply);
		if (prefix("FINISH", reply))
			break;
	}
	close(sock);
	return 0;
}
