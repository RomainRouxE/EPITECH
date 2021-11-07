/*
** EPITECH PROJECT, 2018
** point.c
** File description:
** point.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "char.h"
#include "new.h"
#include "raise.h"

typedef struct
{
	Class base;
	char c;
} CharClass;

static void Char_ctor(Object* self, va_list *args)
{
	((CharClass*)self)->c = va_arg(*args, int);
}

static void Char_dtor(Object* self)
{
	(void) self;
}

static char const *Char_to_string(Object *self)
{
	CharClass *s = (CharClass *)self;
	char *str;

	if(!(str = malloc(sizeof(char))))
		raise("Error of memory");
	sprintf(str, "%c", s->c);
	return (str);
}

static Object *Char_add(const Object* self, const Object* other)
{
	CharClass *s = (CharClass *)self;
	CharClass *o = (CharClass *)other;
	CharClass *res;

	res = new(Char, (s->c) + (o->c));
	return(res);
}

static Object *Char_sub(const Object* self, const Object* other)
{
	CharClass *s = (CharClass *)self;
	CharClass *o = (CharClass *)other;
	CharClass *res;

	res = new(Char, (s->c) - (o->c));
	return(res);
}

static Object *Char_mul(const Object* self, const Object* other)
{
	CharClass *s = (CharClass *)self;
	CharClass *o = (CharClass *)other;
	CharClass *res;

	res = new(Char, (s->c) * (o->c));
	return(res);
}

static Object *Char_div(const Object* self, const Object* other)
{
	CharClass *s = (CharClass *)self;
	CharClass *o = (CharClass *)other;
	CharClass *res;

	res = new(Char, (s->c) / (o->c));
	return(res);
}

static int Char_eq(const Object* self, const Object* other)
{
	CharClass *s = (CharClass *)self;
	CharClass *o = (CharClass *)other;

	if (s->c == o->c)
		return (1);
	return (0);
}

static int Char_gt(const Object* self, const Object* other)
{
	CharClass *s = (CharClass *)self;
	CharClass *o = (CharClass *)other;
	
	if (s->c > o->c)
		return (1);
	return (0);
}

static int Char_lt(const Object* self, const Object* other)
{
	CharClass *s = (CharClass *)self;
	CharClass *o = (CharClass *)other;

	if (s->c < o->c)
		return (1);
	return (0);
}

static CharClass _description = {
	{ sizeof(CharClass), "Char", &Char_ctor,
	  &Char_dtor, &Char_to_string, &Char_add, &Char_sub, &Char_mul,
	  &Char_div, &Char_eq, &Char_gt, &Char_lt},
	  0
};

Class* Char = (Class*) &_description;
