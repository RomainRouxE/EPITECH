/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** my putstr
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
	int x;
	x=0;
	while(str[x] != '\0') {
		my_putchar(str[x]);
		x++;
	}
	return (0);
}
