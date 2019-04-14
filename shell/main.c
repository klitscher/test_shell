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

	(void)ac;
	(void)argv;
	(void)env;
	while (1)
	{
		write(STDERR_FILENO, "$ ", 2);
		getline(&globals.line, &globals.line_len, stdin);
		str_tok = token(globals.line, globals.line_len);
		find_path(env);
		printf("%s\n", globals.path);
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
		free(globals.path);
		free(globals.cpy);
		free(str_tok);
	}
	free(globals.line);
	return (0);
}
