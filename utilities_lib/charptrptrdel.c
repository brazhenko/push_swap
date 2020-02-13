#include <stdlib.h>

void		charptrptrdel(char **ptr)
{
	size_t		i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}