//
// Created by Lommy greenhands Reznak mo reznak on 2020-02-05.
//
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char sym;

	ptr = (unsigned char *)b;
	sym = (unsigned char)c;
	while (len--)
		*ptr++ = sym;
	return (b);
}