#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * exec - executes a command given by the user
 * @argv: number of arguments passed to commande
 * @token: to be used to tokenize the given command
 * @pid: process id
 * @value: check value
 * @input: input from the user
 * @delim: delimiter
 *
 * Return: 0 on success or -1 on failure
 */

int exec(char **argv, char *token, pid_t pid,
		int value, char *input, char *delim)
{
	int argc = 0, i = 0;
	char *input_cp;

	input_cp = strdup(input);
	token = strtok(input, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		argc++;
	}
	argv = malloc(sizeof(char *) * (argc + 1));
	token = strtok(input_cp, delim);
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[argc] = NULL;
	i = 0;
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		while (argv[i])
		{
			value = execve(input_cp, argv, NULL);
			if (value == -1)
			{
				perror("./shell"), free(argv);
				exit(98);
			}
			i++;
		}
	}
	else
		wait(NULL);
	free(input_cp), free(argv);
	return (0);
}

