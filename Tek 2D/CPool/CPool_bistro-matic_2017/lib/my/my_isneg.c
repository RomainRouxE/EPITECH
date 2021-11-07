/*
** EPITECH PROJECT, 2017
** my_isneg.c
** File description:
** print if the number is negative or  if it's positive
*/

void	my_putchar(char c);
int	my_isneg(int n)
{
	if (n < 0)
		my_putchar('N');
	else
		my_putchar('P');
	return (0);
}
