/*
** EPITECH PROJECT, 2017
** my_str_isprintable.c
** File description:
** return if the string contains only lowercase characters
*/

int	my_str_isprintable(char const *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (!(str[i] >= 32))
			return (0);
	}
	return (1);
}
