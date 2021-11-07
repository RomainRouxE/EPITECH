#ifndef MY_H_
# define MY_H_

#include <stdarg.h>
#include <stdlib.h>

typedef int (**t_ptrftab)(va_list, char, const char *, int);

t_ptrftab init_myprintf_ftab();
void my_putchar(char);
void my_putchar_err(char);
void my_putstr_err(char *);
char *my_strdup(char*);
char *my_strcat_err(char *, char *);
char *my_revstr(char *);
int my_printf(const char *, ...);
int get_flag(char);
int check_octal(unsigned char);
int put_octal(unsigned char);
int my_putnbr_base_un(unsigned int, char*);
int my_putnbr_base_lo(unsigned long, char*);
int my_check_empty(const char *, int);
int my_print_d(va_list, char, const char *, int);
int my_print_o(va_list, char, const char *, int);
int my_print_u(va_list, char, const char *, int);
int my_print_x(va_list, char, const char *, int);
int my_print_x2(va_list, char, const char *, int);
int my_print_c(va_list, char, const char *, int);
int my_print_s(va_list, char, const char *, int);
int my_print_s2(va_list, char, const char *, int);
int my_print_p(va_list, char, const char *, int);
int my_print_b(va_list, char, const char *, int);
int my_print_pcent(va_list, char, const char *, int);
int my_printf_nbr(int);
int my_prints(const char *, int *);
int my_print_etc(va_list, char, const char *, int);
int my_put_nbr(int);
int my_putstr(char *);
int my_strlen(char *);
int my_getnbr(char *);
int my_power_rec(int, int);
int my_strcmp(char *, char *);

#endif
