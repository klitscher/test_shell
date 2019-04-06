#include <errno.h>
#include <stdio.h>


int main(void)
{
	char *line __attribute__((unused));
	size_t size;
	ssize_t length;

	errno = 0;
	length = getline(NULL, &size, stdin);
	printf("%ld %d\n", length, errno);
	return (0);
}
