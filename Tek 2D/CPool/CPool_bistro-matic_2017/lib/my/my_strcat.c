/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** concatenate 2 string
*/

char	*my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;

	for (i = 0; dest[i] != '\0'; i++) {}
	for (j = 0; src[j] != '\0'; j++) {
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
