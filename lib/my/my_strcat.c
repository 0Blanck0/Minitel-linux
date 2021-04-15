/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_strcat
** File description:
**      concatenate 2 strings
*/

#include "../../include/my.h"

char *my_strcat(char *dest, const char *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    
    dest[dest_len + i] = '\0';
    return (dest);
}
