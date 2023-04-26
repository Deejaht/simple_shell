#include "main.h"

/**
 * _strcat - appends
 * @dest: first
 * @src: second
 * Return: string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i] != '\0')
		i++;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - string copy
 * @destination: destination string
 * @source: source string
 *
 * Return: destination copy
 */

char *_strcpy(char *destination, char *source)
{
	char *ptr;

	if (destination == NULL)
		return (NULL);
	ptr = destination;
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (ptr);
}

/**
 * _puterr - write a string to stdout
 * @str: string
 * Return: void
 */

void _puterr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

/**
 * _atoi - ascii to integer
 * @str: string to convert
 *
 * Return: int
 */

size_t _atoi(char *str)
{
	long result = 0, i = 0;

	if (str[0] == '+')
	{
		if (_strlen(str) == 1)
			return (INVALID_ATOI);
		i = 1;
		if (_strlen(str) > 11)
			return (INVALID_ATOI);
	}
	if (_strlen(str) > 10)
		return (INVALID_ATOI);
	for (; str[i] != '\0'; i++)
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (INVALID_ATOI);
	}
	if (result > INT_MAX)
		return (INVALID_ATOI);
	return (result);
}
