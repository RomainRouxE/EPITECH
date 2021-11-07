/*
** EPITECH PROJECT, 2017
** my_strcapitalize.c
** File description:
** 
*/
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str)
{
	my_strlowcase(str);
	int	x = 0;
	if(str[0] >= 'a' && str[0] >= 'z')
		str[0] = str[0] - 32;
	while (str[x] != '\0')
	{
		if(str[x] >= 97 && str[x] <= 122)
		{
			if((str[x-1] >= 32 && str[x-1] <= 47) || (str[x-1] >= 58 && str[x-1] <= 64) || (str[x-1] >= 91 && str[x-1] <= 96))
			{
				str[x] = (str[x] - 32);
			}
		}
		x++;
	}
	return (str);
}
char    *my_strlowcase(char *str)
{
        int     x = 0;
        while (str[x] != '\0') {
                if(str[x] >= 'A' && str[x] <= 'Z')
                        str[x] = str[x]+32;
        x++;
        }
        return (str);
}
