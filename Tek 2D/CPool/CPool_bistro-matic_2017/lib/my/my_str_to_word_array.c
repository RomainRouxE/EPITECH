/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** split a string in words
*/

#include <stdlib.h>

int	my_strncpy(char *dest, char const *src, int n);

int	my_is_alphanum(char c)
{
	if (c >= 65 && c <= 90)
		return 1;
	if (c >= 97 && c <= 122)
		return 1;
	if (c >= 48 && c <= 57)
		return 1;
	return 0;
}

int	word_len(char const *str, int i)
{
	int j = i;
	while (my_is_alphanum(str[j]))
			j++;
	return (j - i);
}

int	is_word_begining(char const *str, int i)
{
	if (my_is_alphanum(str[i])) {
		if (i == 0)
			return (1);
		else if (!(my_is_alphanum(str[i - 1])))
			return (1);
	}
	return (0);
}

int	count_words(char const *str)
{
	int words = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (is_word_begining(str, i))
			words++;
			
	}
	return (words);
}

char	**my_str_to_word_array(char const *str)
{
	int words = count_words(str);
	char **tab;
	int y = 0;
	int wlen = 0;
	
	tab = malloc(sizeof(char *) * (words + 1));
	for (int i = 0; str[i] != '\0'; i++) {
		if (is_word_begining(str, i)) {
			wlen = word_len(str, i);
			tab[y] = malloc(sizeof(char) * (wlen + 1));
			my_strncpy(tab[y], &str[i], wlen);
			y++;
		}
	}
	tab[y] = 0;
	return (tab);
}
