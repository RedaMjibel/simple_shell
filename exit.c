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

void xit(char *input, char *delim)
{
	char *input_cp = NULL;
	char *token = NULL;

	input_cp = strdup(input);
	token = strtok(input_cp, delim);
	if (strcmp(token, "exit") == 0)
	{
		free(input_cp);
		free(input);
		exit(0);
	}
}
