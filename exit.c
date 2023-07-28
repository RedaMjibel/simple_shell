#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * xit - exits program
 * @input: user input
 * @delim: delimiter
 *
 * Return: 0 un success
 */

int xit(char *input, char *delim)
{
	char *token = NULL;
	char *buffer = NULL;

	/*if (input == NULL || delim == NULL)
		return (-1);*/
	buffer = strdup(input);
	token = strtok(buffer, delim);
	if (token != NULL && strcmp(token, "exit") == 0)
	{
		free(buffer);
		exit(0);
	}
	free(buffer);
	return (0);
}
