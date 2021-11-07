/*
** EPITECH PROJECT, 2017
** my_strlowcase.c
** File description:
** 
*/
char	*my_strlowcase(char *str)
{
	int	x = 0;
	while (str[x] != '\0') {
		if(str[x] >= 'A' && str[x] <= 'Z')
			str[x] = str[x]+32;
	x++;
	}
	return (str);
}
