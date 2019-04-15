#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>

struct Globals
{
	char *line;
	char *line_cpy;
	size_t line_len;
	char *command;
	char *path;
	char **path_tokens;
} globals;

char *_strcpy(char *dest, char *src, size_t n);
char **token(char *line, size_t bytes);
void find_path(char **envp);
void token_path();

#endif /* _SHELL_H_ */
