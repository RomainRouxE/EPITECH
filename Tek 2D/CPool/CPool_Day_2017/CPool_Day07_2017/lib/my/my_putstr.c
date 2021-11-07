void my_putchar(char c);
int my_putstr(char const *str) {
        int x;
        x=0;
                while(str[x] != '\0') {
                        my_putchar(str[x]);
                        x++;
                }
        return (0);
}
