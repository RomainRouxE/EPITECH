/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header that contain the prototypes exposed in libmy.a
*/

#ifndef MY_H_
	#define MY_H_

	int my_compute_factorial_rec(int);
	int my_compute_power_rec(int, int );
	int my_compute_square_root(int);
	int my_find_prime_sup(int);
	int my_getnbr_base(char const *, char const *);
	int my_getnbr(char const *);
	int my_isneg(int);
	int my_chr_isdigit(char);
	int my_is_prime(int, int);
	void my_putchar(char);
	void my_putnbr_base(int, char const *);
	void my_put_nbr(int);
	void my_putstr(char const *);
	char *my_revstr(char *);
	int my_showmem(char const *, int);
	int my_showstr(char const *);
	void my_sort_int_array(int *, int);
	char *my_strcapitalize(char *);
	char *my_strcat(char *, char const *);
	int my_strcmp(char const *, char const *);
	char *my_strcpy(char *, char const *);
	int my_str_isalpha(char const *);
	int my_str_islower(char const *);
	int my_str_isnum(char const *);
	int my_str_isprintable(char const *);
	int my_str_isupper(char const *);
	int my_strlen(char const *);
	char *my_strlowcase(char *);
	char *my_strncat(char *, char const *, int);
	int my_strncmp(char const *, char const *, int);
	char *my_strncpy(char *, char const *, int);
	char *my_strstr(char const *, char const *);
	char *my_strdup(char const *);
	char **my_str_to_word_array(char const *);
	int my_show_word_array(char * const *);
	char *my_strupcase(char *);
	void my_swap(int *, int *);
	int my_str_contain(char const *str, char c);
#endif
