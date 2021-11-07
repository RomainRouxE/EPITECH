/*
** EPITECH PROJECT, 2017
** my_print_alpha.c
** File description:
** exe
*/
void my_putchar(char c);
int my_print_alpha(void)
{
	int letter;
	letter = 'a';
	while (letter <= 'z') {
		my_putchar(letter);
		letter ++;
       	}
	return (0);
}
