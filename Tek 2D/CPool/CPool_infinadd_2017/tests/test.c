/*
** EPITECH PROJECT, 2017
** test infadd
** File description:
** test add
*/

#include <criterion/criterion.h>
#incldue "../include/my.h"

void evalexpr(char *expr); //test '+'
Test(serie1, 1)
{
	cr_assert_str_eq(infadd("1+1"), 2);
}

Test(serie1, 2)
{
 	cr_assert_str_eq(infadd("5+5"), 10);
}

Test(serie1, 3)
{
 	cr_assert_str_eq(infadd("50+50"), 100);
}

Test(serie1, 4)
{
 	cr_assert_str_eq(infadd("123456789 + 123456789"), 246913578);
}

Test(serie1, 5)
{
 	cr_assert_str_eq(infadd("100   +         23"), 123);
}

void evalexpr(char *expr); //test '-'
Test(serie1, 1)
{
        cr_assert_str_eq(infadd("10-1"), 9);
}

Test(serie2, 1)
{
        cr_assert_str_eq(infadd("5+5"), 10);
}

Test(serie3, 1)
{
 	cr_assert_str_eq(infadd("50+50"), 100);
}

Test(serie4, 1)
{
        cr_assert_str_eq(infadd("123456789 + 123456789"), 246913578);
}

Test(serie5, 1)
{
        cr_assert_str_eq(infadd("100   +         23"), 123);
}

void evalexpr(char *expr);
Test(serie1, 1)
{
        cr_assert_str_eq(infadd("1+1"), 2);
}
Test(serie2, 1)
{
        cr_assert_str_eq(infadd("5+5"), 10);
}

Test(serie3, 1)
{
 	cr_assert_str_eq(infadd("50+50"), 100);
}

Test(serie4, 1)
{
        cr_assert_str_eq(infadd("123456789 + 123456789"), 246913578);
}

Test(serie5, 1)
{
        cr_assert_str_eq(infadd("100   +         23"), 123);
}

void evalexpr(char *expr);
Test(serie1, 1)
{
        cr_assert_str_eq(infadd("1+1"), 2);
}
Test(serie2, 1)
{
        cr_assert_str_eq(infadd("5+5"), 10);
}

Test(serie3, 1)
{
 	cr_assert_str_eq(infadd("50+50"), 100);
}

Test(serie4, 1)
{
        cr_assert_str_eq(infadd("123456789 + 123456789"), 246913578);
}

Test(serie5, 1)
{
        cr_assert_str_eq(infadd("100   +         23"), 123);
}

void evalexpr(char *expr);
Test(serie1, 1)
{
        cr_assert_str_eq(infadd("1+1"), 2);
}
void evalexpr(char *expr);
Test(serie1, 1)
{
        cr_assert_str_eq(infadd("1+1"), 2);
}
void evalexpr(char *expr);
Test(serie1, 1)
{
        cr_assert_str_eq(infadd("1+1"), 2);
}
void evalexpr(char *expr);
Test(serie1, 1)
{
        cr_assert_str_eq(infadd("1+1"), 2);
}
