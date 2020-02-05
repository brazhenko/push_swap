//
// Created by Lommy greenhands Reznak mo reznak on 2020-02-05.
//
#include "utilities.h"
#include <stdlib.h>

char	*strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s || !(sub = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(sub, &s[start], len));
}