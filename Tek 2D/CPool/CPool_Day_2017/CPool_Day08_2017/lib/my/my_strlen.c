int my_strlen(char const *str)
{
	int x;
	x=0;
	while(str[x] != '\0') {
		x++;
	}
	return (x);
}
