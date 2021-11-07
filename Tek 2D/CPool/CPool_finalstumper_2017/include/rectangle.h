/*
** EPITECH PROJECT, 2017
** rectangle
** File description:
** rectangle const: {ul_c, ur_c, ll_c, lr_c, v_b, h_b}
*/

#ifndef RECTANGLE_H_

#define RECTANGLE_H_

void prepare_array_and_test(char *, int, int);
int test_rectangle(char *, int, int, char *, int);
void test_rectangle_loop(char *, int, int);

char const rush1_1_array[] = {'o', 'o', 'o', 'o', '|', '-'};
char const rush1_1_array_small[] = {'\0', '\0', '\0', '\0', 'o', 'o'};
char const rush1_3_array[] = {'A', 'A', 'C', 'C', 'B', 'B'};
char const rush1_4_array[] = {'A', 'C', 'A', 'C', 'B', 'B'};
char const rush1_5_array[] = {'A', 'C', 'C', 'A', 'B', 'B'};
char const rush1_2_array[] = {'/', '\\', '\\', '/', '*', '*'};

#endif
