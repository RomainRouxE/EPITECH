/*
** EPITECH PROJECT, 2017
** my_chr_isdigit.c
** File description:
** return 0 if the char is digit
*/

int	my_chr_isdigit(char c)
{
	if (c >= 48 && c <= 57) 
		return (1);
	return (0);
}
