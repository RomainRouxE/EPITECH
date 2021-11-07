/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
**
*/
char	*my_strcpy(char *dest, char const *src) {
	int	x = 0;
	while (src[x] != '\0') {
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
