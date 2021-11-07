/*
** EPITECH PROJECT, 2017
** testi_unit_D08.c
** File description:
** 
*/

#include <criterion/criterion.h>
#include <string.h>
cTest(serie1, 1)
{

 	cr_assert_str_eq(infadd("1","1"), 2);
}


har *my_strdup(char const *src);
Test(serie1, 1)
{
	char const *arr ="bonjours";
	cr_assert_str_eq(my_strdup(arr),strdup(arr));
}

Test(serie2, 2)
{
        char const *arr = "    ";
        cr_assert_str_eq(my_strdup(arr),strdup(arr));
}


Test(serie3, 3)
{
	char const *arr = "abcdefghijklmnopqrstuvwxyz";
	cr_assert_str_eq(my_strdup(arr),strdup(arr));
}
		
Test(serie4, 4)
{
        char const *arr = "1234abcd ; 56789efghij ";
        cr_assert_str_eq(my_strdup(arr),strdup(arr));
}
