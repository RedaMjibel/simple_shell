#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int exec(char **argv, char *token, pid_t,
		char *input, char *delim);
int _chdir(void);

char* input_check(char *buffer, char *input);

#endif
