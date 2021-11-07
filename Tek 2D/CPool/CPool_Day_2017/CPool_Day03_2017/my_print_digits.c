/*
** EPITECH PROJECT, 2017
** my_print_digits.c
** File description:
** 
*/
void my_puchar(char c);
int my_print_digits(void)
{
        int number;
        number = '0';
        while (number <= '9')
                {
                        my_putchar(number);
                        number ++;
                }
	return (0);
}
