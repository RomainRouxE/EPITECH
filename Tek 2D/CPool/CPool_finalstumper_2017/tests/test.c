/*
** EPITECH PROJECT, 2017
** test evalexpr
** File description:
** test priority
*/

#include <criterion/criterion.h>

char* rush3(char *buffer); //test rush1-1

Test(serie1, 1)
{
	cr_assert_str_eq(eval_expr("1 1"), 2);
}

Test(serie1, 2)
{
	cr_assert_eq(eval_expr("5+5"), 10);
}

Test(serie1, 3)
{
	cr_assert_eq(eval_expr("50+50"), 100);
}

Test(serie1, 4)
{
	cr_assert_eq(eval_expr("123456789 + 123456789"), 246913578);
}

Test(serie1, 5)
{
	cr_assert_eq(eval_expr("100   +         23"), 123);
}

//test '-'

Test(serie2, 1)
{
	cr_assert_eq(eval_expr("10-1"), 9);
}

Test(serie2, 2)
{
	cr_assert_eq(eval_expr("10-50"), -40);
}

Test(serie2, 3)
{
	cr_assert_eq(eval_expr("-50-50"), -100);
}

Test(serie2, 4)
{
	cr_assert_eq(eval_expr("-12   - 134"), -146);
}

Test(serie2, 5)
{
	cr_assert_eq(eval_expr("100-90-80-70"), -140 );
}

//test '*'

Test(serie3, 1)
{
	cr_assert_eq(eval_expr("2*2"), 4);
}

Test(serie3, 2)
{
	cr_assert_eq(eval_expr("5*5"), 25);
}

Test(serie3, 3)
{
	cr_assert_eq(eval_expr("15*15"), 225);
}

Test(serie3, 4)
{
	cr_assert_eq(eval_expr("-60*50"), -3000);
}

Test(serie3, 5)
{
	cr_assert_eq(eval_expr("-1*2*-3*4*5*6*7*8*9*10"), 3628800);
}

//test '/'

Test(serie4, 1)
{
	cr_assert_eq(eval_expr("4/2"), 2);
}

Test(serie4, 2)
{
	cr_assert_eq(eval_expr("-20 / 4"), -5);
}

Test(serie4, 3)
{
	cr_assert_eq(eval_expr("20   / -5"), -4);
}

Test(serie4, 4)
{
	cr_assert_eq(eval_expr("-650/-50"), 13);
}

Test(serie4, 5)
{
	cr_assert_eq(eval_expr("-100/2/-2/5"), 5);
}

//test '%'

Test(serie5, 1)
{
	cr_assert_eq(eval_expr("1%1"), 0);
}

Test(serie5, 2)
{
	cr_assert_eq(eval_expr("10 % 3"), 1);
}

Test(serie5, 3)
{
	cr_assert_eq(eval_expr("610%23"), 12);
}

//test '/'

Test(serie6, 1)
{
	cr_assert_eq(eval_expr("1+2*3+4"), 11);
}

Test(serie6, 2)
{
	cr_assert_eq(eval_expr("50/5*5"), 50);
}

Test(serie6, 3)
{
	cr_assert_eq(eval_expr("100 % 13  + 123*3"), 378);
}

Test(serie6, 4)
{
	cr_assert_eq(eval_expr("5000%123*4/2+1234"), 1394);
}

Test(serie6, 5)
{
	cr_assert_eq(eval_expr("173*57-89%7"), 9856);
}
