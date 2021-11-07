/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** 
*/
char	*my_strncat(char *dest, char const *src, int nb)
{
        int	x = 0;
        int	y = 0;
        while(dest[x] != '\0')
                x++;
        while(src[y] != '\0' || y < nb) {
                dest[x+y] = src[y];
                y++;
        }
        dest[x+nb] = '\0';
        return (dest);
}
