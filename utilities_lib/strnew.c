//
// Created by Lommy greenhands Reznak mo reznak on 2020-02-05.
//
#include <stdlib.h>
#include "utilities.h"

char	*ft_strnew(size_t size)
{
	char		*ret;

	ret = (char *)xmalloc(sizeof(char) * (size + 1));
	ft_memset(ret, 0, sizeof(char) * (size + 1));
	return (ret);
}