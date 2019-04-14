#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * _strncpy - copy n bytes of memory to a new allocated location
 * @dest: new memory location
 * @src: old memory location
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src, size_t n)
{
	size_t i;

	if (dest == NULL)
		exit(9);
	for (i = 0; src[i] != '\0' && n > 0; i++, n--)
		dest[i] = src[i];
	return (dest);
}
