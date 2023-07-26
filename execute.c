#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute - executes the code
 * @argv: arguments passed by the user
 * @pid: process id
 *
 * Return: 0 on success or -1 on faliure
 */

int execute(char **argv, pid_t pid)
{

	if (!access(argv[0], R_OK))
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	else
	{
		perror("./shell");
		return (-1);
	}
	return (0);
}