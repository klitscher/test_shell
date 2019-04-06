#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i;
	int status;
	pid_t parent;
	pid_t my_pid;

	parent = getpid();
	printf("Parent id is: %d\n", parent);
	for (i = 5; i > 0; i--)
	{
		my_pid = fork();
		if (my_pid == 0)
		{
			my_pid = getpid();
			printf("Child_pid =******* %u *******\n", my_pid);
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
