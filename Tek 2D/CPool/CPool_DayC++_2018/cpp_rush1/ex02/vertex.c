/*
** EPITECH PROJECT, 2018
** vertex
** File description:
** vertex
*/

#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct
{
	Class base;
	int x;
	int y;
	int z;
}VertexClass;

static void Vertex_ctor(Object* self, va_list *args)
{
	(void)args;
	(void) self;
	((VertexClass*)self)->x = va_arg(*args, int);
	((VertexClass*)self)->y = va_arg(*args, int);
	((VertexClass*)self)->z = va_arg(*args, int);
}

static void Vertex_dtor(Object* self)
{
	(void)self;
}

static int int_size(int i)
{
	int res = 0;

	if (i < 0) {
		res++;
		i *= -1;
	}
		
	if (i == 0)
		return (1);
	for (res = 0; i > 0; res++)
		i /= 10;
	return (res);
}

static char const *Vertex_to_string(Object *self)
{
	int i = 0;
	int x;
	int y;
	int z;
	char *str;

	int_size(i);
	str = malloc(sizeof(char *) * i);
	x = ((VertexClass*)self)->x;
	y = ((VertexClass*)self)->y;
	z = ((VertexClass*)self)->z;
	sprintf(str, "<Vertex (%d, %d, %d)>", x, y, z);
	return (str);
}

static VertexClass _description = {
	{sizeof(VertexClass), "Vertex",
	 &Vertex_ctor, &Vertex_dtor, &Vertex_to_string },
	0, 0, 0,
};

Class* Vertex = (Class*) &_description;
