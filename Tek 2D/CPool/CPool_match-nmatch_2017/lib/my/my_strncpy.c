/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** my strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	int x = 0;
	while (x <= n-1) {
		dest[x] = src[x];
		x++;
	}
	return (dest);
}
