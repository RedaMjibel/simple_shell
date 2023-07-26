#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * input_check - checks input
 * @buffer: buffer
 * @input: user input
 *
 * Return: input + path
 */

char *input_check(char *buffer, char *input)
{
	char *dirlim = "/";
	char *ktoken = NULL;
	char *temp = NULL;
	char *tempcp = NULL;

	tempcp = strdup(input);
	ktoken = strtok(tempcp, dirlim);
	if (strcmp(ktoken, "bin") != 0)
	{
		_chdir();
		getcwd(buffer, 1024);
		strcat(buffer, dirlim);
		strcat(buffer, ktoken);
		temp = strdup(buffer);
		free(tempcp), free(ktoken);
		return (temp);
	}
	free(tempcp), free(ktoken);
	return (input);
}
