#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"

char **token(char *line, size_t bytes)
{
	char *delim = " \n\r\t";
	char *sac;
	char **token;
	size_t i = 0;

	globals.cpy = malloc(bytes);
	sac = _strcpy(globals.cpy, line, bytes + 1);
	token = malloc(sizeof(char *) * globals.line_len + 1);
	sac = strtok(globals.line, delim);
	token[i] = sac;
	while (sac != NULL)
	{
		i++;
		sac = strtok(NULL, delim);
		token[i] = sac;
	}
	free(sac);
	return (token);
}

/* void find_path(char **envp) */
/* { */
/* 	char *path = "PATH="; */
/* 	int i, j; */

/* 	for (i = 0; envp[i] != NULL; i++) */
/* 	{ */
/* 		for (j = 0; envp[i][j] != '\0' && j < 5; ) */
/* 		{ */
/* 			if (envp[i][j] == path[j]) */
/* 			{ */
/* 				j++; */
/* 			} */
/* 			else */
/* 			{ */
/* 				break; */
/* 			} */
/* 		} */
/* 		if (path[j] = '\0') */
/* 		{ */
/* 			for (j = 0; envp[i][j]; j++) */
/* 				; */
/* 			globals.path = malloc(sizeof(char) * j); */
/* 			if (globals.path == NULL) */
/* 				exit(100); */
/* 			_strcpy(globals.path, envp[i]); */
/* 		} */
/* 	} */
/* 	write(STDERR_FILENO; "NOT FOUND\n"; 10); */
/* 	exit(99); */
/* } */
