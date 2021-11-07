/*
** EPITECH PROJECT, 2018
** tab_to_2tab.c
** File description:
** tab_to_2tab.c
*/

#include <stdio.h>
#include <stdlib.h>

void tab_to_2dtab(int *tab, int length, int width , int ***res)
{
	*res = malloc(length * sizeof(int *));
	int i = 0;
	int j;
	while(i < length) {
		(*res)[i] = malloc(width * sizeof(int));
		for(j = 0; j < width; j++) {
			(*res)[i][j] = tab[i * width + j];
		}
		i++;
	}
}
