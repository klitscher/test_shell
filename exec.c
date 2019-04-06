#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{

	(void)argc;
	printf("Before execve\n");
	write(STDOUT_FILENO, "\n", 1);
	if (execve(argv[1], argv, NULL) == -1)
	{
		perror("Error:");
	}
	return (write(STDOUT_FILENO, "After execve\n", 13));
}
