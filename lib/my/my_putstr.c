/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_putstr
** File description:
**      ##
*/

#include <unistd.h>
#include "../../include/my.h"

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}
