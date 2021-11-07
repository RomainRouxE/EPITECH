/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** my strlen
*/

int my_strlen(char const *str)
{
	int x;
	x=0;
	while(str[x] != '\0') {
		x++;
	}
	return (x);
}
