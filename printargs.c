#include <stdio.h>

int main(__attribute__ ((unused))int ac, char **av)
{
	/*int i = 0;*/

	/* while (av[i] != NULL) */
	/* { */
	/* 	printf("%s\n", av[i]); */
	/* 	i++; */
	/* } */
	while (*av != NULL)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}
