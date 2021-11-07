/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** return if the string contains only alphabetical characters
*/

int	my_str_isalpha(char const *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (!(str[i] >= 65 && str[i] <= 90) &&
				(!(str[i] >= 97 && str[i] <= 122)))
			return (0);
	}
	return (1);
}
