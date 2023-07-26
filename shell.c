#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - entry point
 * @ac: number of arguments passed to the program
 * @av: the arguments passed
 * Return: allways 0
 */

int main(int ac, char **av)
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
		if (n == 15736)
		{
			printf("%d%s\n", ac, *av);
		}
		exec(argv, token, pid, input, delim, av);
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
		exec(argv, token, pid, input, delim, av);
		printf("#cisfun$ ");
	}
	free(input);
	return (0);
}
