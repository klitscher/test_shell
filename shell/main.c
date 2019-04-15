#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"
int main(int ac, char **argv, char **env)
{
	char **str_tok;
	pid_t my_pid;
	int status;
	size_t bytes;

	(void)ac;
	(void)argv;
	(void)env;
	while (1)
	{
		write(STDERR_FILENO, "$ ", 2);
		globals.line_len = getline(&globals.line, &bytes, stdin);
		str_tok = token(globals.line, globals.line_len);
		find_path(env);
		token_path();
		printf("tokenized path 0: %s\n", globals.path_tokens[0]);
		printf("tokenized path 1: %s\n", globals.path_tokens[1]);
		my_pid = fork();
		if (my_pid == 0)
		{
			execve(str_tok[0], str_tok, NULL);
			free(str_tok);
			free(globals.line);
			exit(127);
		}
		else
		{
			wait(&status);
		}
		free(globals.path_tokens[0]);
		free(globals.path_tokens);
		free(globals.path);
		free(globals.line_cpy);
		free(str_tok);
	}
	free(globals.line);
	return (0);
}
