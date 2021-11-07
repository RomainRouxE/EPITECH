/*
** EPITECH PROJECT, 2018
** point.c
** File description:
** point.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "float.h"
#include "new.h"
#include "raise.h"

typedef struct
{
	Class base;
	float i;
} FloatClass;

static void Float_ctor(Object* self, va_list *args)
{
	((FloatClass*)self)->i = va_arg(*args, double);
}

static void Float_dtor(Object* self)
{
	//FloatClass *s = (FloatClass *)self;
	(void)self;
	//if (s->base)
	//	free(s->base);
}

static int float_size(float i)
{
	int res = 0;

	if (i < 0) {
		res++;
		i *= -1;
	}
	if (i == 0)
		return (1);
	while (i > (int)i)
		i *= 10;
	for (; i > 0; res++)
		i /= 10;
	return (res);
}

static char const *Float_to_string(Object *self)
{
	FloatClass *s = (FloatClass *)self;
	char *str;

	if(!(str = malloc(sizeof(char) * (float_size(s->i) + 2))))
		raise("Error of memory");
	sprintf(str, "%g", s->i);
	return (str);
}

static Object *Float_add(const Object* self, const Object* other)
{
	FloatClass *s = (FloatClass *)self;
	FloatClass *o = (FloatClass *)other;
	FloatClass *res;

	res = new(Float, (s->i) + (o->i));
	return(res);
}

static Object *Float_sub(const Object* self, const Object* other)
{
	FloatClass *s = (FloatClass *)self;
	FloatClass *o = (FloatClass *)other;
	FloatClass *res;

	res = new(Float, (s->i) - (o->i));
	return(res);
}

static Object *Float_mul(const Object* self, const Object* other)
{
	FloatClass *s = (FloatClass *)self;
	FloatClass *o = (FloatClass *)other;
	FloatClass *res;

	res = new(Float, (s->i) * (o->i));
	return(res);
}

static Object *Float_div(const Object* self, const Object* other)
{
	FloatClass *s = (FloatClass *)self;
	FloatClass *o = (FloatClass *)other;
	FloatClass *res;

	res = new(Float, (s->i) / (o->i));
	return(res);
}

static int Float_eq(const Object* self, const Object* other)
{
	FloatClass *s = (FloatClass *)self;
	FloatClass *o = (FloatClass *)other;

	if (s->i == o->i)
		return (1);
	return (0);
}

static int Float_gt(const Object* self, const Object* other)
{
	FloatClass *s = (FloatClass *)self;
	FloatClass *o = (FloatClass *)other;
	
	if (s->i > o->i)
		return (1);
	return (0);
}

static int Float_lt(const Object* self, const Object* other)
{
	FloatClass *s = (FloatClass *)self;
	FloatClass *o = (FloatClass *)other;

	if (s->i < o->i)
		return (1);
	return (0);
}

static FloatClass _description = {
	{ sizeof(FloatClass), "Int", &Float_ctor,
	  &Float_dtor, &Float_to_string, &Float_add, &Float_sub, &Float_mul,
	  &Float_div, &Float_eq, &Float_gt, &Float_lt},
	  0
};

Class* Float = (Class*) &_description;
