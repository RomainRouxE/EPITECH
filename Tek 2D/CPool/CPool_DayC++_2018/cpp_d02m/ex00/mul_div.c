/*
** EPITECH PROJECT, 2018
** mul_div.c
** File description:
** mul_div.c
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
	*sum = first + second;
	*product = first * second;
}

void add_mul_2param(int *first, int *second)
{
	*first = *first + *second;
	*second = (*first - *second) * *second;
}
