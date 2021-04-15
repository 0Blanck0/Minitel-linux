/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_str_to_word_array
** File description:
**      splits an array into words
*/

#include <stdlib.h>

int my_strlen(const char *s);

int my_isalnum(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int my_word_len(const char *str, int cpt)
{
    int ret = 0;

    while (my_isalnum(str[cpt])) {
        ret++;
        cpt++;
    }
    return (ret);
}

int my_nb_words(const char *str)
{
    int cpt = 0;
    int first_letter = 1;
    int ret = 0;

    while (str[cpt] != '\0') {
        if (my_isalnum(str[cpt])) {
            if (first_letter && my_isalnum(str[cpt]))
                ret++;
            first_letter = 0;
        } else
            first_letter = 1;
        cpt++;
    }
    return (ret);
}

char **my_str_to_word_array(const char *str)
{
    char **ret;
    int nb_words = my_nb_words(str);
    int cpt = 0;
    int ret_cpt1 = 0;
    int ret_cpt2;

    if (nb_words == 0) {
        ret = (char **)malloc(0);
        return (ret);
    }
    ret = (char **)malloc(sizeof(char *) * (nb_words + 1));
    if (ret == 0)
        return (0);
    while (cpt < my_strlen(str) && str[cpt]) {
        while (!my_isalnum(str[cpt]))
            cpt++;
        if (cpt < my_strlen(str) && my_isalnum(str[cpt])) {
            ret_cpt2 = 0;
            ret[ret_cpt1] = (char *)malloc(sizeof(char) * (my_word_len(str, cpt) + 1));
            if (ret[ret_cpt1] == 0)
                return (0);
            while (my_isalnum(str[cpt]))
                ret[ret_cpt1][ret_cpt2++] = str[cpt++];
            ret[ret_cpt1++][ret_cpt2] = '\0';
        }
    }
    ret[ret_cpt1] = 0;
    return (ret);
}
