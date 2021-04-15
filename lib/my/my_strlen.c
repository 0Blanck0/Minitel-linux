/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_strlen
** File description:
**      ##
*/

#include <unistd.h>

int my_strlen(const char *s)
{
    const char *str;

    str = s;
    if (!s)
        return (0);
    while (*str)
        str++;
    return (str-s);
}
