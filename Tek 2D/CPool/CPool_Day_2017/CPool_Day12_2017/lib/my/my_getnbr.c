/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** get_nbr
*/

int counter(char const *str, int *j);

int my_getnbr(char const *str)
{
	int	i = 0, *j = &i, k;
	long	num = 0;

	if(counter(str, j))
		return 0;
	k = i - 1;
	while(str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	i = k;
	while(i >= 0 && (str[i] == '-' || str[i] == '+')) {
		if(str[i] == '-')
			num *= -1;
		i--;
	}
	return(num);
}

int counter(char const *str, int *j)
{
	int i = *j;
	
	while('0' > str[i] || str[i] > '9') {
		if(str[i] == '\0')
			return (1);
		i++;
	}
	*j = i;
	return (0);
}
