#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char my_putchar(char c)
{
	write (1, &c, 1);
}

int my_putstr(char const *str)
{
	int x = 0;

	while (str[x] != '\0') {
		my_putchar(str[x]);
		x++;
	}
	return (0);
}

int main(void)
{
	char *s = get_next_line(0);

	while (s) {
		my_putstr(s);
		my_putchar('\n');
		free(s);
		s = get_next_line(0);
	}
	return (0);
}
