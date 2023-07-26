#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - entry point
 *
 * Return: allways 0
 */

int main(void)
{
	size_t n = 1;
	int check;
	pid_t pid = 0;
	char *delim = " \n", *token = NULL, *input_cp = NULL;
	char **argv = NULL;
	char *input = malloc(sizeof(char) * n);

	if (!isatty(fileno(stdin)))
	{
		getline(&input, &n, stdin);
		exec(argv, token, pid, input, delim);
		exit(0);
	}
	printf("#cisfun$ ");
	while ((check = getline(&input, &n, stdin)) != -1)
	{
		input_cp = strdup(input);
		token = strtok(input_cp, delim);
		if (token == NULL)
		{
			free(input_cp);
			printf("#cisfun$ ");
			continue;
		}
		if (strcmp(token, "exit") == 0)
		{
			free(input_cp);
			free(input);
			exit(0);
		}
		free(input_cp);
		exec(argv, token, pid, input, delim);
		printf("#cisfun$ ");
	}
	free(input);
	return (0);
}
