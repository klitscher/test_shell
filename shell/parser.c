#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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


void find_path(char **envp)
{
	char *path = "PATH=";
	size_t i, j;

	for (i = 0; envp[i] != NULL; i++)
	{
		for (j = 0; envp[i][j] != '\0' && j < 5; )
		{
			if (envp[i][j] == path[j])
			{
				j++;
			}
			else
			{
				break;
			}
		}
		if (path[j] == '\0')
		{
			for (j = 0; envp[i][j] != '\0'; j++)
				;
			printf("j is: %lu\n", j);
			/* Need to free this at some point, prolly when I call end the loop*/
			globals.path = malloc(sizeof(char) * j + 1);
			if (globals.path == NULL)
				exit(100);
			_strcpy(globals.path, envp[i], j);
			globals.path[j] = '\0';
			return;
		}
	}
	write(STDERR_FILENO, "NOT FOUND\n", 10);
	exit(99);
}
