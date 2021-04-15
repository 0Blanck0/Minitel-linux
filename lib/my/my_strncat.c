/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_strcat
** File description:
**      concatenate 2 strings
*/

int my_strlen(const char *s);

char *my_strncat(char *dest, const char *src, int n)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < n){
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
