int my_strlen(char const *str)
{
	int x;
	x=1;
	while(str[x] != '\0') {
		x++;
	}
	return (x);
}
