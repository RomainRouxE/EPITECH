/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** Return the number in the string
*/

int	isDigit(char c)
{
	if (c >= 48 && c <= 57) 
		return (1);
	return (0);
}

int	len_num(char const *str, int position)
{
	int len = 0;
	while (isDigit(str[len + position]) == 1)
		len++;
	return (len);
}

int	power_of_ten(int p)
{
	int	power = 10;
	for (int i = 1; i < p; ++i)
		power = power * 10;
	return (power);
}

int	limits_of_int(long long l)
{
	if (l < -2147483648 || l > 2147483647)
		return (1);
	return (0);
}

int	test_negativity(char const *str)
{
	int cpt = 0;

	for (int i = 0; str[i] == '+' || str[i] == '-'; i++)
		if (str[i] == '-')
			cpt++;
	return cpt;
}

int	my_getnbr(char const *str)
{
	int isNeg = 0;
	int pos = 0;
	long long nbr = 0;
	
	//if (str[0] == '-' || str[0] == '+')
	isNeg = test_negativity(str);
	for (pos = 0; str[pos] == '+' || str[pos] == '-'; pos++){}
	int num_l = len_num(str, pos);
	char tab[num_l];
	int power = num_l - 1;

	for (int j = 0; j < num_l; ++j)
		tab[j] = str[pos + j];
	for(int j = 0; j < num_l; ++j) {
		if (j == (num_l - 1))
			nbr = nbr + (tab[j] - 48);
		else
			nbr = nbr + ((tab[j] - 48) * power_of_ten(power));
		power--;
	}
	if (isNeg % 2 == 1)
		nbr = nbr * (-1);
	if (limits_of_int(nbr) == 1)
		return 0;
	return (nbr);
}
