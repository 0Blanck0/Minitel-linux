/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_subremove
** File description:
**      Remove sub string
*/

#include <stdlib.h>
#include <string.h>

void my_subremove(char *str, const char *toRemove) 
{
    const size_t remLen = strlen(toRemove);
    char *copyEnd;
    char *copyFrom = str + remLen;

    while (NULL != (copyEnd = strstr(copyFrom, toRemove))) {  
        memmove(str, copyFrom, copyEnd - copyFrom);

        str += copyEnd - copyFrom;
        copyFrom = copyEnd + remLen;
    }

    memmove(str, copyFrom, 1 + strlen(copyFrom));
}