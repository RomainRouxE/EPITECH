/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** return a copy of the given string
*/

#include <stdlib.h>

int	my_strlen(char *str);
char	*my_strcpy(char *dest, char const *src);

char	*my_strdup(char const *src)
{
	int len = my_strlen((char *)src);
	char *str;
	
	str = malloc(sizeof(char) * (len + 1));
	return my_strcpy(str, src);
}
