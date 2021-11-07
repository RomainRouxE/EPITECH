/*
** EPITECH PROJECT, 2017
** lib3.c
** File description:
** lib3 minishell1
*/

#include "struct.h"

char *my_strcocat(char *str1, char *str2)
{
	char *tmp;
	int i = -1;
	int j = 0;

	tmp = malloc((my_strlen(str1) + my_strlen(str2) + 1) * sizeof(*tmp));
	while (str1[++j])
		tmp[i] = str1[i];
	while (str2[j])
		tmp[i++] = str2[j++];
	tmp[i] = 0;
	return (tmp);
}

void *xmalloc(unsigned int size)
{
	void *output;

	if ((output = malloc(size)) == NULL) {
		write(0, "Could not allo!\n", 16);
		exit(0);
	}
	return (output);
}
