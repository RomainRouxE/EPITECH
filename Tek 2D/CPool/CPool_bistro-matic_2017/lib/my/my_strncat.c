/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** concatenate n charcaters of 2 string
*/

char	*my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int j = 0;

	for (i = 0; dest[i] != '\0'; i++) {}
	for (j = 0; src[j] != '\0' && j < nb; j++) {
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
