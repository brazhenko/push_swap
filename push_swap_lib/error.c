//
// Created by Lommy greenhands Reznak mo reznak on 2020-02-05.
//

#include <zconf.h>
#include <stdlib.h>

void		error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}