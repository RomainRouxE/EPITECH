char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;
	while(dest[i] != '\0')
		i++;
	while(src[j]) {
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}
