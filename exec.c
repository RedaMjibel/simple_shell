#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * exec - executes a command given by the user
 * @argv: arguments passed to commande
 * @token: to be used to tokenize the given command
 * @pid: process id
 * @input: input from the user
 * @delim: delimiter
 *
 * Return: 0 on success or -1 on failure
 */

int exec(char **argv, char *token, pid_t pid, char *input, char *delim)
{
	int argc = 0, i = 0;
	char *input_cp = NULL;
	char buffer[1024];
	char *newdir = "//root//simple_shell";
	char *inputbuff;

	input_cp = input_check(buffer, input);
	inputbuff = strdup(input);
	token = strtok(inputbuff, delim);
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
	chdir(newdir);
	execute(argv, pid, input_cp);
	free(input_cp), free(argv), free(token), free(inputbuff);
	return (0);
}
