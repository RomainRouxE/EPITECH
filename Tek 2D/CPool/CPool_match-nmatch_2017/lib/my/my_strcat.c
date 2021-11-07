/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** my strcat
*/

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;
	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
		dest[i+j] = src[j];
	dest[i+j] = '\0';
	return (dest);
}
