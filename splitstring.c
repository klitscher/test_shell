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
void _splitstring(char *str)
{
	char *token;
	int i;
	int count = 1;

	token = strtok(str, " ");
	printf("Token = %s\n", token);
	while (token != NULL)
	{
		/* NOT SURE WHY BUT COUNT IS OFF BY ONE FOR INITIAL TOKEN*/
		if (count > 0)
		{
			for (i = 0; token[i] != '\0'; i++)
			{
			}
			write(STDOUT_FILENO, token, i);
			write(STDOUT_FILENO, "\n", 1);
			printf("Printf int = %d\n", i);
			token = strtok(NULL, " ");
		}
		/*LOOP FOR EVERY OTHER TOKEN NOT THE FIRST*/
		else
		{
			for (i = 0; token[i] != '\0'; i++)
			{
			}
			i--;
			write(STDOUT_FILENO, token, i);
			write(STDOUT_FILENO, "\n", 1);
			printf("Printf int = %d\n", i);
			token = strtok(NULL, " ");
		}
		/*USED TO MAKE SURE WE NEVER GO BACK INTO FIRST IF*/
		count--;
	}
}
