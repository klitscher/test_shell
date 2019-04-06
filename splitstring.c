#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * _splitstring - used to split a string into tokens and get the strlen count of each token
 * @str: String to do things to
 *
 * Return: void
 */
char **_splitstring(char *str)
{
	char *token;
	char **buff;
	int i, j;
	int count = 0;

	/* used malloc cause can't return static array i guess? */
	buff = malloc(100);
	token = strtok(str, " ");
	printf("Token = %s\n", token);
	buff[count] = token;
	/*used to get the length of and print out the token and len*/
	while (token != NULL)
	{
		count++;
		for (j = 0, i = 0; token[i] != '\0'; j++, i++)
		{
			if (token[i] == '\n')
				j--;
		}
		write(STDOUT_FILENO, token, j);
		write(STDOUT_FILENO, "\n", 1);
		printf("Printf int = %d\n", j);
		token = strtok(NULL, " ");
		buff[count] = token;
	}
	while (count >= 0)
	{
		printf("Buff[%d] is %s\n", count, buff[count]);
		count--;
	}
	return (buff);
}
