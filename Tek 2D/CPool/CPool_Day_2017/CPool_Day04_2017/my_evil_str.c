Reproduce the behavior of the
strstr
function. /*
** EPITECH PROJECT, 2017
** my_evil_str.c
** File description:
** 
*/
int my_evil_str(char const *str) {
        int x = 0;
	int y = 0;
	int ptr = 0;
	while(str[x] != '\0') {
		x++;
	}
	while(y <= x) {
		ptr=str[y];
		y=str[x];
		x=ptr;
		x--;
		y++;
	}
	return (0);
}
