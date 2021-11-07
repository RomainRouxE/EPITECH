/*
** EPITECH PROJECT, 2017
** test 
** File description:
** test bistro
*/

#include <criterion/criterion.h>
#include "../include/bistro-matic.h"

//test '+'
/*int cmp_str(char *s1,char *s2)
{
	int x = 0;
	
	if (my_strlen(s1) != my_strlen(s2))
		return(84);
	while (s1[x] != '\0') {
		if (s1[x] != s2[x])
			     return(84);
		x++;
	}
	return(1);
	}*/

Test(serie1_1, 1)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "1+2", 3), 3);
	//cr_assert(cmp_str(eval_expr("0123456789", "()+-*/%", "1+2", 3), "3") == 1);
}

Test(serie1_2, 2)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "5+5", 3), 10);
}

Test(serie1_3, 3)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "50+50", 5), 100);
}

//Test(serie1_4, 4)
//{
//	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "123456789+123456789", 20), 246913578);
//}

Test(serie1_5, 5)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "100+23", 29), 123);
}

//Test(serie1_6, 6)
//{
//      cr_assert_eq(eval_expr("0123456789", "()+-*/%", "100000000000000+100000000000000", 20), 200000000000000);
//}

//test '-'

Test(serie2_1, 1)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "10-1", 20), 9);
}

Test(serie2_2, 2)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "10-50", 20), -40);
}

Test(serie2_3, 3)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "-50-50", 20), -100);
}

Test(serie2_4, 4)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "-12-134", 20), -146);
}

Test(serie2_5, 5)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "100-90-80-70", 20), -140 );
}

//Test(serie2_6, 6)
//{
//	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "-10000000000-10000000000", 20), -20000000000);
//}

//test '*'

Test(serie3_1, 1)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "2*2", 20), 4);
}

Test(serie3_2, 2)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "5*5", 20), 25);
}

Test(serie3_3, 3)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "15*15", 20), 225);
}

Test(serie3_4, 4)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "-60*50", 29), -3000);
}

//Test(serie3_5, 5)
//{
//	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "-1*2*-3*4*5*6*7*8*9*10", 20), 3628800);
//}

//test '/'

Test(serie4_1, 1)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "4/2", 20), 2);
}

Test(serie4_2, 2)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "-20/4", 20), -5);
}

Test(serie4_3, 3)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "20/-5", 20), -4);
}

Test(serie4_4, 4)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "-650/-50", 20), 13);
}

//Test(serie4_5, 5)
//{
//	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "-100/2/-2/5", 20), 5);
//}

//test '%'

Test(serie5_1, 1)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "1%1", 20), 0);
}

Test(serie5_2, 2)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "10%3", 20), 1);
}

Test(serie5_3, 3)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "610%23", 20), 12);
}

//test '/'

Test(serie6_1, 1)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "1+2*3+4", 20), 11);
}

//Test(serie6_2, 2)
//{
//	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "50/5*5", 20), 50);
//}

Test(serie6_3, 3)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "100%13+123*3", 20), 378);
}

//Test(serie6_4, 4)
//{
//	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "5000%123*4/2+1234", 20), 1394);
//}

//Test(serie6_5, 5)
//{
//	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "173*57-89%7", 20), 9856);
//}

//test '()'

Test(serie7_1, 1)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "(1+2)", 20), 3);
}

Test(serie7_2, 2)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "2*(1+2)", 20), 6);
}

Test(serie7_3, 3)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "2+3*(4-1)", 20), 11);
}

Test(serie7_4, 4)
{
	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "2*(2+4)", 20), 12);
}

//Test(serie7_5, 5)
//{
//	cr_assert_eq(eval_expr("0123456789", "()+-*/%", "(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))", 100), -744629760);
//}
