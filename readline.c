#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void _splitstring(char *str);

int main()
{
	size_t sz = 0;
	ssize_t b_r = 0;
	char *string = NULL;
	/*char *token;*/

	/* Writing $* as prompt */
	write(STDOUT_FILENO, "$ ", 2);

	/* Autoallocating memory using getline and storing the input in that memory*/
	b_r = getline(&string, &sz, stdin);

	/* checking if getline fails */
	if (b_r == -1)
		return (-1);

	/* printing the new string stored in the getline allocated buffer */
	printf("%s\n", string);

	_splitstring(string);

        /* freeing the memory allocated by getline */
	free(string);
	return (0);
}
