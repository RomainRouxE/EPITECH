/*
** EPITECH PROJECT, 2017
** lib.c
** File description:
** lib1 minishell1
*/

#include "struct.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	int i = 0;

	while (str[i])
		my_putchar(str[i++]);
}

int my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i + 1);
}

char *my_strdup(char *str)
{
	char *tab;
	int i = 0;

	if ((tab = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[i] != '\0') {
		tab[i] = str[i];
		i = i + 1;
	}
	tab[i] = '\0';
	return (tab);
}

char *my_nstrdup(char *str)
{
	char *tab;
	int i = 0;

	if ((tab = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != ':') {
		tab[i] = str[i];
		i = i + 1;
	}
	tab[i] = '\0';
	return (tab);
}
