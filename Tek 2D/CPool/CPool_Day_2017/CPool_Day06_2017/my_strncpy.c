/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** 
*/
char	*my_strncpy(char *dest, char const *src, int n) {
	int	x = 0;
	while (x <= n-1 && src[x] != '\0') {
		dest[x] = src[x];
		x++;
	}
	if (src[x] == '\0')
		dest[x] = '\0';
	return (dest);
}
