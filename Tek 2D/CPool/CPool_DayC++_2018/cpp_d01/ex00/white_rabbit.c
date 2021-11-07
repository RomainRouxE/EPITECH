/*
** EPITECH PROJECT, 2018
** follow_the_white_rabbit.c
** File description:
** print direction of the rabbit
*/

#include <stdlib.h>
#include <stdio.h>

int follow_the_white_rabbit(void)
{
	static int x = 0;
	int y = random() % 37;

	if (y == 0)
		x = x + 37;
	x = x + y;
	if ((y >= 4 && y <= 6) || (y >= 17 && y <= 21) || y == 28)
		printf("left\n");
	if (y == 13 || y > 33 && y < 37)
		printf("right\n");
	if (y == 10 || y == 15 || y == 23)
		printf("forward\n");
	if (y == 8 || y == 16 || y == 24 || y == 26 || y == 32)
		printf("backward\n");
	if (y == 1 || y == 0 || x >= 397) {
		printf("RABBIT!!!\n");
		return (x);
	}
	else
		follow_the_white_rabbit();
}
