/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_strcmp
** File description:
**      compares 2 string
*/

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
