/*
** EPITECH PROJECT, 2017
** lib2.c
** File description:
** lib2 minishell1
*/

#include "struct.h"

int count_words(char *str, char separator)
{
	int i = 0;
	int total = 0;

	while (str[i] != '\0') {
		if (str[i] == separator) {
			total = total + 1;
		}
		i = i + 1;
	}
	return (total + 1);
}

char *my_put_in_tab(char *str, int *i, char separator)
{
	char *out;
	int k = 0;

	while (str[*i] == separator && str[*i])
		*i = *i + 1;
	while (str[*i + k] != separator && str[*i + k])
		k = k + 1;
	out = xmalloc(sizeof(char) * (k + 1));
	out[k] = 0;
	k = 0;
	while (str[*i] != separator && str[*i]) {
		out[k] = str[*i];
		k = k + 1;
		*i = *i + 1;
	}
	return (out);
}

char **my_str_to_wordtab(char *str, char separator)
{
	char **wordtab;
	int i;
	int j;

	if (count_words(str, separator)) {
		i = 0;
		j = 0;
		wordtab = xmalloc(sizeof(char*) * (count_words(str, separator) + 1));
		wordtab[count_words(str, separator)] = 0;
		while (str[i] && j < count_words(str, separator)) {
			wordtab[j] = my_put_in_tab(str, &i, separator);
			j = j + 1;
		}
		return (wordtab);
	}
	else
		return (NULL);
}

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0) {
		i = i + 1;
	}
	return (s1[i] - s2[i]);
}

int my_strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n) {
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}
