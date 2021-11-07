/*
** EPITECH PROJECT, 2018
** new
** File description:
** new
*/

#include <string.h>
#include <stdarg.h>
#include "raise.h"
#include "object.h"
#include "new.h"

Object *new(Class* class, ...)
{
	Class *newClass;
	va_list ap;

	if (class == NULL)
		raise("error");
	if (!(newClass = (Class *)malloc(class->__size__)))
		raise("error");
	memcpy (newClass, class, class->__size__);
	va_start(ap, class);
	newClass->__init__(newClass, &ap);
	va_end(ap);
	return (newClass);
}

Object *va_new(Class *class, va_list *ap)
{
	Class *newClass;

	if (class == NULL)
		raise("error");
	if (!(newClass = (Class *)malloc(class->__size__)))
		raise("error");
	memcpy (newClass, class, class->__size__);
	newClass->__init__(newClass, ap);
	return (newClass);
}

void delete(Object* ptr)
{
	if (ptr) {
		if (((Class*)ptr)->__del__)
			((Class*)ptr)->__del__(ptr);
		free(ptr);
	}
}
