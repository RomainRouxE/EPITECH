/*
** EPITECH PROJECT, 2018
** point.c
** File description:
** point.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "int.h"
#include "new.h"
#include "raise.h"

typedef struct
{
	Class base;
	int i;
} IntClass;

static void Int_ctor(Object* self, va_list *args)
{
	((IntClass*)self)->i = va_arg(*args, int);
}

static void Int_dtor(Object* self)
{
	(void) self;
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
	for (; i > 0; res++)
		i /= 10;
	return (res);
}

static char const *Int_to_string(Object *self)
{
	IntClass *s = (IntClass *)self;
	char *str;

	if(!(str = malloc(sizeof(char) * (int_size(s->i) + 1))))
		raise("Error of memory");
	sprintf(str, "%d", s->i);
	return (str);
}

static Object *Int_add(const Object* self, const Object* other)
{
	IntClass *s = (IntClass *)self;
	IntClass *o = (IntClass *)other;
	IntClass *res;

	res = new(Int, (s->i) + (o->i));
	return(res);
}

static Object *Int_sub(const Object* self, const Object* other)
{
	IntClass *s = (IntClass *)self;
	IntClass *o = (IntClass *)other;
	IntClass *res;

	res = new(Int, (s->i) - (o->i));
	return(res);
}

static Object *Int_mul(const Object* self, const Object* other)
{
	IntClass *s = (IntClass *)self;
	IntClass *o = (IntClass *)other;
	IntClass *res;

	res = new(Int, (s->i) * (o->i));
	return(res);
}

static Object *Int_div(const Object* self, const Object* other)
{
	IntClass *s = (IntClass *)self;
	IntClass *o = (IntClass *)other;
	IntClass *res;

	res = new(Int, (s->i) / (o->i));
	return(res);
}

static int Int_eq(const Object* self, const Object* other)
{
	IntClass *s = (IntClass *)self;
	IntClass *o = (IntClass *)other;

	if (s->i == o->i)
		return (1);
	return (0);
}

static int Int_gt(const Object* self, const Object* other)
{
	IntClass *s = (IntClass *)self;
	IntClass *o = (IntClass *)other;
	
	if (s->i > o->i)
		return (1);
	return (0);
}

static int Int_lt(const Object* self, const Object* other)
{
	IntClass *s = (IntClass *)self;
	IntClass *o = (IntClass *)other;

	if (s->i < o->i)
		return (1);
	return (0);
}

static IntClass _description = {
	{ sizeof(IntClass), "Int", &Int_ctor,
	  &Int_dtor, &Int_to_string, &Int_add, &Int_sub, &Int_mul,
	  &Int_div, &Int_eq, &Int_gt, &Int_lt},
	  0
};

Class* Int = (Class*) &_description;
