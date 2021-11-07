/*
** EPITECH PROJECT, 2017
** my_strcapitalize.c
** File description:
** capitalize the first letter of each words
*/

char	*my_strcapitalize(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		if (str[i] >= 97 && str[i] <= 122) {
			if (i == 0)
				str[i] -= 32;
			else if (!(str[i - 1] > 96 && str[i - 1] < 123) &&
					!(str[i - 1] > 64 && str[i - 1] < 91) &&
					!(str[i - 1] > 47 && str[i - 1] < 58))
				str[i] -= 32;
		}
	}
	return (str);
}
