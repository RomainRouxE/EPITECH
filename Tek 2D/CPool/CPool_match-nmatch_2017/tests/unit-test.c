/*
** EPITECH PROJECT, 2017
** unit-test.c
** File description:
** test unit
*/
#include <criterion/criterion.h>
int match(char const *s1, char const *s2);
Test(serie01, Task1)
{
	cr_assert_eq(match("abcdef", "abcdef"), 1);
	cr_assert_eq(match("12345", "12345"), 1);
	cr_assert_eq(match("abc  123  ...", "abc  123  ..."), 1);
	cr_assert_eq(match("", ""), 1);
}

Test(serie02, Task1)
{
	cr_assert_eq(match("", "abc"), 0);
	cr_assert_eq(match("abc", ""), 0);
	cr_assert_eq(match("1234", "12345"), 0);
	cr_assert_eq(match("AZERTY", "AZERTy"), 0);
}
