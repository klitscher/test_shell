#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * token - turns the command entered into a toke
 * @line: the getlined command that was entered
 * @len: the length of the string getline returned, minus the null byte
 *
 * Return: a pointer to the tokenized command
 */
char **token(char *line, size_t len)
{
	char *delim = " \n\r\t";
	char *sac;
	char **token;
	size_t i = 0;

	/*making a copy of getline*/
	globals.line_cpy = malloc(len + 1);
	sac = _strcpy(globals.line_cpy, line, len + 1);
	/*initializing last byte in array to null, else uninitialized value*/
	globals.line_cpy[len] = '\0';
	token = malloc(sizeof(char *) * globals.line_len + 1);
	sac = strtok(globals.line_cpy, delim);
	token[i] = sac;
	while (sac != NULL)
	{
		i++;
		sac = strtok(NULL, delim);
		token[i] = sac;
	}
	return (token);
}

/**
 * find_path - find the PATH variable in the envp
 * @envp: pointer to the environment variables
 */
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
			/* free'd this at end of the main loop*/
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

/**
 * token_path - tokenize the PATH variable and store in global
 */
void token_path()
{
	int i, j, k, l = 0;
	int tokens = 1;
	char *delim = ":";
	char *sac;
	char *sac2;

	for (i = 0; globals.path[i] != '\0'; i++)
		;
	/*malloc space for path after = */
	sac = malloc(sizeof(char) * (i + 1) - 5);
	for (k = 0, j = 5; globals.path[j] != '\0'; k++, j++)
		sac[k] = globals.path[j];
	sac[k] = '\0';
	sac2 = strtok(sac, delim);
	while (sac2 != NULL)
	{
		sac2 = strtok(NULL, delim);
		tokens++;
	}
	free(sac);
	
        /*need to free this*/
	globals.path_tokens = malloc(sizeof(char *) * tokens);
	sac = malloc(sizeof(char) * (i + 1) - 5);
	for (k = 0, j = 5; globals.path[j] != '\0'; k++, j++)
		sac[k] = globals.path[j];
	sac[k] = '\0';
	sac2 = strtok(sac, delim);
	globals.path_tokens[l] = sac2;
	while (sac2 != NULL)
	{
		l++;
		sac2 = strtok(NULL, delim);
		globals.path_tokens[l] = sac2;
	}
	return;
}
