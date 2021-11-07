/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** task 3
*/

int my_putstr(char const *str);
void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
	int x = 0;
	while (tab[x] != 0) {
		my_putstr(tab[x]);
		my_putchar('\n');
		x++;
	}
	return(0);
}
