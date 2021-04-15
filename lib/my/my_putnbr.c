/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_putnbr
** File description:
**      ##
*/

void my_putchar(char c);

void my_putnbr(int n)
{
    unsigned int nb;

    nb = n;
    if (n < 0) {
        nb = -n;
        my_putchar('-');
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    else {
        my_putchar (nb + 48);
    }
}
