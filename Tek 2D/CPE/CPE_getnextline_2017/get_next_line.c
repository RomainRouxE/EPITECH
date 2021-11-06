/*
** EPITECH PROJECT, 2017
** getnextline.c
** File description:
** get next line
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char *final_check(char *string, int x, int y)
{
	char *str;

	if (x == -1)
		return (NULL);
	if ((str = malloc(sizeof(char) * 1)) == NULL)
		return (NULL);
	str[0] = '\0';
	if (x != READ_SIZE && string == NULL && y == 0)
		return (NULL);
	else if (string == NULL)
		return (str);
	return (string);
}

char *error(char buffer[READ_SIZE], int *i, int *o)
{
	if (buffer[*i] == '\n' && *o != 0)
		*o = *o - 1;
	if (buffer[*i] == '\n' && *i == 0 && READ_SIZE != 1)
		*i = *i + 1;
	else if (buffer[*i] == '\n' && *i == READ_SIZE - 1)
		*i = 0;
	else if (buffer[*i] == '\n' && READ_SIZE != 1)
		*i = *i + 1;
	if (*o == 0)
		*i = 0;
}

char *string(char *string, char buffer)
{
	static int e = 0;
	char *str;
	int x = 0;

	if (string == NULL)
		e = 0;
	else
		e = e + 1;
	if ((str = malloc(sizeof(char) * (e + 2))) == NULL)
		return (NULL);
	for (; x < e; x++) {
		str[x] = string[x];
	}
	str[x] = buffer;
	str[x + 1] = '\0';
	free(string);
	return (str);
}

int if_error(int fd, char **buffer, int *str, int *i)
{
	if (*buffer == NULL)
		*buffer = malloc(sizeof(char) * READ_SIZE);
	if (fd == -1 || READ_SIZE <= 0)
		return (-1);
	if ((*str = read(fd, *buffer, READ_SIZE)) == -1)
		return (-1);
	*i = 0;
	return (*str);
}

char *get_next_line(int fd)
{
	static char *buffer = NULL;
	static int i = 0;
	static int x = 0;
	static int y = 0;
	char *str = NULL;

	if (i == 0)
		if ((x = if_error(fd, &buffer, &y, &i)) <= 0)
			return (NULL);
	for (; buffer[i] != '\n' && y != 0 && x != 0;) {
		y--;
		if ((str = string(str, buffer[i])) == NULL)
			return (NULL);
		if (i == READ_SIZE - 1)
			x = if_error(fd, &buffer, &y, &i);
		else
			i++;
	}
	str = final_check(str, x, y);
	error(buffer, &i, &y);
	return (str);
}
