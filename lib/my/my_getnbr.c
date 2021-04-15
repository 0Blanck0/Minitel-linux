/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_getnbr
** File description:
**      ##
*/

int my_getnbr(const char *str)
{
    int cpt = 0;
    long ret = 0;
    int ret_final;
    int sign = 0;
    int cpt2;

    while (str[cpt] && (str[cpt] < '0' || str[cpt] > '9')) {
        if (str[cpt] != '-' && str[cpt] != '+')
            return (0);
        cpt++;
    }
    while (str[cpt] && str[cpt] >= '0' && str[cpt] <= '9') {
        cpt2 = cpt - 1;
        while (cpt2 >= 0 && (str[cpt2] == '-' || str[cpt2] == '+')) {
            if (str[cpt2] == '-')
                sign++;
            cpt2--;
        }
        ret = ret * 10 + (str[cpt] - 48);
        cpt++;
    }
    if (sign % 2 == 1)
        ret = -ret;
    if (ret > 2147483647 || ret < -2147483648)
        ret = 0;
    ret_final = ret;
    return (ret_final);
}
