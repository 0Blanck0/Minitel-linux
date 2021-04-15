/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_isneg
** File description:
**      ##
*/

#include <unistd.h>

void my_putchar(char c);

void my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
}
