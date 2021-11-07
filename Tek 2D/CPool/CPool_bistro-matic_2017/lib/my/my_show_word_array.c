/*
** EPITECH PROJECT, 2017
** my_show_word_array.c
** File description:
** display content of an array
*/

void	my_putstr(char *str);

int	my_show_word_array(char * const *tab)
{
	for (int i = 0; tab[i] != 0; i++)
		my_putstr(tab[i]);
	return (0);
}
