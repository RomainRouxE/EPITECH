/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** 
*/
char	*my_revstr(char *str) {
	int	x = 0;
	int	y = 0;
	char	ptr = 0;
	while(str[x] != '\0') {
		x++;
	}
	x--;
	while (y < x) {
		ptr = str[x];
		str[x] = str[y];
		str[y] = ptr;
		x--;
		y++;
	}
	return (str);
}
