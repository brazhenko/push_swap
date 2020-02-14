
#include "utilities.h"
#include <stdlib.h>

char	*strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s || !(sub = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(sub, &s[start], len));
}