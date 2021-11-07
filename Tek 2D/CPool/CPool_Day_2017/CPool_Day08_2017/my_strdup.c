/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** task 1
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
	int x = 0;
	char *str;

	str = malloc(sizeof(char) * (my_strlen(src) + 1));
	while (src[x] != '\0') {
		str[x] = src[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
