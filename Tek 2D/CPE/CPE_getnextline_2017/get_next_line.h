/*
** EPITECH PROJECT, 2017
** CPE_getnextline.h
** File description:
** get next line h
*/


#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
#define READ_SIZE	4095
#endif

char *error(char buffer[READ_SIZE], int *i, int *o);
char *get_next_line(int fd);
char *string(char *string, char buffer);

#endif
