/*
** EPITECH PROJECT, 2018
** point.c
** File description:
** point.c
*/

#include <stdio.h>
#include "point.h"
#include <stdarg.h>
#include "stdlib.h"

typedef struct
{
    Class base;
	int x, y;
} PointClass;

static void Point_ctor(Object* self, va_list *args)
{
	(void) args;
	(void) self;
	((PointClass*)self)->x = va_arg(*args, int);
	((PointClass*)self)->y = va_arg(*args, int);
}

static void Point_dtor(Object* self)
{
	(void) self;
}

static int int_size(int i)
{
	int res = 0;

	if (i < 0) {
		res++;
		i *= 10;
	}
		if (i == 0)
		return (1);
	for (res = 0; i > 0; res++)
		i /= 10;
	return(res);
}

static char const *Point_to_string(Object *self)
{
	int i = 0;
	int x;
	int y;
	char *str;

	int_size(i);
	str = malloc(sizeof(char *) * i);
	x = ((PointClass*)self)->x;
	y = ((PointClass*)self)->y;
	sprintf(str, "<Point (%d, %d)>", x, y);
	return (str);
}

static PointClass _description = {
	{ sizeof(PointClass), "Point", &Point_ctor,
	  &Point_dtor, &Point_to_string },
	0, 0
};

Class* Point = (Class*) &_description;
