/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int binary(va_list print);
int hex(va_list print);
int carac(va_list print);
int octal(va_list print);
int pointeur(va_list print);
int count(va_list print, int count_n);
int decimal(va_list print);
int string(va_list print);
int integ(va_list print);
int redirect(int arg, va_list print, int count_n);
void my_putnbr_base(unsigned int nb, char *base);
int my_put_nbr(int nb);
int my_strlen(char *str);
int my_putstr(char const *str);
void my_putchar(char c);

#endif
