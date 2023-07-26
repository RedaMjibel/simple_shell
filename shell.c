#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - entry point.
 *
 *
 * Return: allways 0.
 */

int main(void)
{
	size_t n = 1;
	int value = 0, check;
	pid_t pid = 0;
	char *delim = " \n", *token = NULL;
	char **argv = NULL;
	char *input = malloc(sizeof(char) * n);

	if (!isatty(fileno(stdin)))
	{
		getline(&input, &n, stdin);
		exec(argv, token, pid, value, input, delim);
		free(input);
		exit(0);
	}
	printf("#cisfun$ ");
	check = getline(&input, &n, stdin);
	if (check == EOF)
	{
		free(input);
		return (-1);
	}
	while (input)
	{
		exec(argv, token, pid, value, input, delim);
		printf("#cisfun$ ");
		check = getline(&input, &n, stdin);
		if (check == -1)
		{
			free(input);
			exit(98);
		}
	}
	free(input);
	return (0);
}

