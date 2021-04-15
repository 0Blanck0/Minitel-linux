/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_strcpy
** File description:
**      copies a string to dest
*/

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return (dest);
}
