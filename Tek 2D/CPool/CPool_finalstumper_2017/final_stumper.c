/*
** EPITECH PROJECT, 2017
** final_stumper
** File description:
** detects which rush1 rectangle, prints size
*/

#include "subf.h"
#include "my.h"

int get_height(char *rec)
{
	int i;
	int height;

	i = 0;
	height = 0;
	while (rec[i] != '\0') {
		if (rec[i] == '\n')
			++height;
		++i;
	}
	if (rec[i - 1] != '\n')
		++height;
	return height;
}

int check_first_or_last_line(char *buffer, int len, char h_border, int start_pos)
{
	int i;

	for (i = start_pos; i < len - 2; i++) {
	        if (buffer[i] != h_border) {
		        my_putstr("none\n");
		        return 0;
		}
	}
	return 1;
}

int check_middle_lines(char *buffer, int i, int len, char v_border)
{
	int is_border;
	int j;
	int char_to_cmp;

	for (j = i; j < i + len; j++) {
		is_border = (j == i || j == i + len - 1);
		char_to_cmp = (is_border == 1) ? v_border : ' ';
		if (buffer[j] != char_to_cmp) {
			my_putstr("none\n");
			return 0;
		}
	}
	return 1;
}

void rush3(char *buffer)
{
	int len;
	char array[6];
	int i;
	int height;

	height = get_height(buffer);
	for (len = 0; buffer[len] != '\n' && buffer[len] != '\0'; len++);
	array[0] = buffer[0];
	array[1] = buffer[len - 1];
	array[5] = buffer[1];
	if (check_first_or_last_line(buffer, len, array[5], 1) == 0)
		return;
	array[4] = buffer[len + 1];
	for (i = len + 1; i <= len * (height - 1); i += len + 1) {
		if (check_middle_lines(buffer, i, len, array[4]) == 0)
			return;
	}
	array[2] = buffer[i];
	array[3] = buffer[i + len - 1];
	if (check_first_or_last_line(buffer, len, array[5], i + 1) == 0)
		return;
	prepare_array_and_test(array, len, height);
	my_putchar('\n');
}
