/*
** EPITECH PROJECT, 2018
** func_ptr.h
** File description:
** func_ptr.h
*/

#ifndef __FUNC_PTR_H__
#define __FUNC_PTR_H__

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "func_ptr_enum.h"

typedef void (*t_func)(char *str);

typedef struct s_action_func {
	action_t action;
	t_func func;
} t_action_func;

#endif
