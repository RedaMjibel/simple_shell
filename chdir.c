#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _chdir - changes the working directory to bin
 *
 * Return: 0 on success -1 on failure
 */

int _chdir(void)
{
	char *newdir = "//bin//";

	if (chdir(newdir) == -1)
	{
		return (-1);
	}
	return (0);
}
