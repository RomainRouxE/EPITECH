/*
** EPITECH PROJECT, 2017
** my_strupcase.c
** File description:
** 
*/
char	*my_strupcase(char *str)
{
	int	x = 0;
	
	while (str[x] != '\0') {
		if(str[x] >= 'a' && str[x] <= 'z')
			str[x] = (str[x]-32);
		x++;
	}
        return (str);
}
