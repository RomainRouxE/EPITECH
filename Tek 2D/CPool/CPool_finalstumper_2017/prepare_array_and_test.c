/*
** EPITECH PROJECT, 2017
** prepare_array_and_test
** File description:
** subfunctions for final_stumper
*/

#include "my.h"
#include "rectangle.h"

int test_rectangle(char *array, int len, int height, char *rush, int print_or)
{
	int i;
	int score;
	char const *const_array;

	if (rush[7] == '1') {
		if (height + len <= 3)
			const_array = rush1_1_array_small;
		else
			const_array = rush1_1_array;
	}
	if (rush[7] == '2')
		const_array = rush1_2_array;
	if (rush[7] == '3')
		const_array = rush1_3_array;
	if (rush[7] == '4')
		const_array = rush1_4_array;
	if (rush[7] == '5')
		const_array = rush1_5_array;
	score = 0;
	for (i = 0; i < 7; i++) {
		if (array[i] == '\0' || const_array[i] == array[i])
			++score;
	}
	if (score == i - 1) {
		if (print_or == 1)
			my_putstr(" || ");
		my_putstr(rush);
		my_put_nbr(len);
		my_putchar(' ');
		my_put_nbr(height);
		return 1;
	}
	return 0;
}

void test_rectangle_loop(char *array, int len, int height)
{
	int print_or;
	int print_none;

	print_none = 0;
	print_or = test_rectangle(array, len, height, "[rush1-1] ", 0);
	print_none += print_or;
	print_or = test_rectangle(array, len, height, "[rush1-2] ", print_or);
	print_none += print_or;
	print_or = test_rectangle(array, len, height, "[rush1-3] ", print_or);
	print_none += print_or;
	print_or = test_rectangle(array, len, height, "[rush1-4] ", print_or);
	print_none += print_or;
	print_none += test_rectangle(array, len, height, "[rush1-5] ", print_or);
	if (print_none == 0)
		my_putstr("none");
}

void prepare_array_and_test(char *array, int len, int height)
{
	if (height == 2 && len != 1)
		array[4] = '\0';
	if (len == 2 && height != 1)
		array[5] = '\0';
	if (height == 1) {
		if (len != 1)
			array[4] = '\0';
		else
			array[4] = array[0];
		array[0] = '\0';
		array[1] = '\0';
		array[2] = '\0';
		array[3] = '\0';
	}
	if (len == 1) {
		array[0] = '\0';
		array[1] = '\0';
		array[2] = '\0';
		array[3] = '\0';
		array[5] = '\0';
	}
	test_rectangle_loop(array, len, height);
}
