/*
** EPITECH PROJECT, 2017
** my_swap.c
** File description:
** 
*/
void my_swap(int *a, int *b)
{
	int ptr;
	ptr =* a;
	*a = *b;
	*b = ptr;
}
