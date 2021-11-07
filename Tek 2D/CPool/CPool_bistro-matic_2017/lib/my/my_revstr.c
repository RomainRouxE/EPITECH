/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** reverse a string
*/

int	my_strlen(char *str);
void	my_putchar(char c);

char	*my_revstr(char *str)
{
	int len = 0;
	int j = 0;
	char c;

	len = my_strlen(str);
	j = len - 1;
	for (int i = 0; i < len / 2; i++) {
		c = str[j];
		str[j] = str[i];
		str[i] = c;
		j--;
	}
	return (str);
}
