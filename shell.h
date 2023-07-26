#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int exec(char **argv, char *token, pid_t pid, int value,
		char *input, char *delim);

#endif

