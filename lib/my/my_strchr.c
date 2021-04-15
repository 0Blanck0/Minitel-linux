/*
** ETNA PROJECT, 24/02/2021 by elisab_a
** my_strchr
** File description:
**      ##
*/

#include <stdlib.h>

char	*my_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}