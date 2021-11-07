/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** write a string
*/

void	my_putchar(char c);
int	my_putstr(char const *str)
{
	for(int i = 0; str[i] != '\0'; i++){
		my_putchar(str[i]);
	}
	return (0);
}
