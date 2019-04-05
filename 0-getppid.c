#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;
	pid_t ppid;

	pid = getpid();
	ppid = getppid();
	printf("My process ID is: %u\n", pid);
	printf("My parent process ID is: %u\n", ppid);
	return (0);
}
