/*
** ETNA PROJECT, 24/02/2021
** myMinitel
** File description:
**      [...]
*/

#include "../include/my.h" 

int my_sys_len(FILE *file) 
{
    long len = 0;
    char ch;

    while ((ch=fgetc(file)) != EOF)
        len ++;

    return len;
}

char *my_system(char *str, char *opt)
{
    FILE *p;
    char *ret = 0;
    char ch;
    long len = 0;

    p = popen(str, opt);

    if ( p == NULL) {
        ret = "Unable to open process";
        return ret;
    }

    len = my_sys_len(popen(str, opt));
    ret = malloc(len * sizeof(char *));

    while ((ch=fgetc(p)) != EOF)
        ret = my_strncat(ret, &ch, 1);

    pclose(p);
    return ret;
}
