/*
** EPITECH PROJECT, 2017
** my_str_contain.c
** File description:
** return 1 if string contain the char c
*/

int	my_str_contain(char const *str, char c)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
			return 1;
	}
	return 0;
}
