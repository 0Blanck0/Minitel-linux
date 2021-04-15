/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_putchar
** File description:
**      prints a character
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
