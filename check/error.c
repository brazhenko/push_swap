#include <unistd.h>
#include <stdlib.h>

void		error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}