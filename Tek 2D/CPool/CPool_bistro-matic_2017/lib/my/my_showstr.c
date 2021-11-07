/*
** EPITECH PROJECT, 2017
** my_showstr.c
** File description:
** print non printable characters in hexadecimal
*/

int	my_putnbr_base(int nbr, char const *base);
void	my_putchar(char c);

int	my_showstr(char const *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 31) {
			my_putchar('\\');
			if (str[i] < 16)
				my_putchar('0');
			my_putnbr_base(str[i], "0123456789abcdef");
		}
		else
			my_putchar(str[i]);
	}
	return (0);
}
