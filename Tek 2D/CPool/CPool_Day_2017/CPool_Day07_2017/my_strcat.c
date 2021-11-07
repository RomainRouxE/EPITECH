/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** 
*/
char	*my_strcat(char *dest, char const *src)
{
	int	x = 0;
	int	y = 0;
	while(dest[x] != '\0')
		x++;
	while(src[y] != '\0') {
		dest[x+y] = src[y];
		y++;
	}
	dest[x+y] = '\0';
	return (dest);
}
