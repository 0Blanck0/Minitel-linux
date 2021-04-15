/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_strncpy
** File description:
**      copies n char from src to dest
*/

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
