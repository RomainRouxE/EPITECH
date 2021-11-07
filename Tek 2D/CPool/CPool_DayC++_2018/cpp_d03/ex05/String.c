/*
** EPITECH PROJECT, 2018
** String.c
** File description:
** String.c
*/

#include "String.h"

void StringDestroy(String *this)
{
	if (this && this->str)
		free(this->str);
}

static void assign_s(String *this, String const *str)
{
	if ((str != NULL) && (this != NULL)) {
		StringDestroy(this);
		this->str = strdup(str->str);
	}
}

static void assign_c(String *this, char const *str)
{
	if (str && this) {
		StringDestroy(this);
		this->str = strdup(str);
	}
}

static void append_s(String *this, String const *ap)
{
	if (ap && ap->str && this) {
		if (this->str)
			this->str = strcat(this->str, ap->str);
		else
			this->str = strdup(ap->str);
	}
}

static void append_c(String *this, char const *ap)
{
	if ((ap != NULL) && (this != NULL)) {
		if (this->str != NULL)
			this->str = strcat(this->str, ap);
		else
			this->str = strdup(ap);
	}
}

static char at(String *this, size_t pos)
{
	size_t	i = 0;

	if (this && this->str) {
		while (this->str[i] != '\0') {
			if (i == pos)
				return (this->str[i]);
			i++;
		}
	}
	return (-1);
}

static void clear(String *this)
{
	if (this && this->str)
		this->str = memset(this->str, 0, strlen(this->str));
}

static int size(String *this)
{
	int i = 0;

	if (this && this->str) {
		while (this->str[i] != '\0')
			i++;
		return (i);
	}
	return (-1);
}

void StringInit(String *this, char const *s)
{
	if (this) {
		this->str = strdup(s);
		this->assign_s = &assign_s;
		this->assign_c = &assign_c;
		this->append_s = &append_s;
		this->append_c = &append_c;
		this->at = &at;
		this->clear = &clear;
		this->size = &size;
	}
}
