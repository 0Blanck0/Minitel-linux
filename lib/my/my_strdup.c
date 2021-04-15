/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_strdup
** File description:
**      copies a string in an allocated new one
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(const char *src)
{
    int len = my_strlen(src);
    char *dest;

    dest = (char *)malloc((sizeof(char) * (len + 1)));
    if (!dest)
    	return (0);
    dest = my_strcpy(dest, src);
    dest[len] = '\0';
    return (dest);
}
