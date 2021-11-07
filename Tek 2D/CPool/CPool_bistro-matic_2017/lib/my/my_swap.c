/*
** EPITECH PROJECT, 2017
** my_swap.c
** File description:
** Switch content of two variables
*/
void	my_swap(int *a, int *b)
{
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}
