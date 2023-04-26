#include "main.h"

/**
 * _strdup - allocate space for string
 * @str: string to alloc space for
 *
 * Return: allocated string
 */

char *_strdup(char *str)
{
	int size, i;
	char *new_str;

	size = _strlen(str);
	i = 0;
	new_str = malloc(sizeof(char) * size + 1);

	if (new_str == NULL)
		exit(12);
	while (i < size)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/**
 * free_str_arr - free allocated string array
 * @str_arr: allocated string array
 *
 * Return: void
 */

void free_str_arr(char **str_arr)
{
	int i;

	i = 0;

	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

/**
 * split_string - split string into array of chars
 * @str: string to split
 * @delim: delimiter
 *
 * Return: str_array
 */

char **split_string(char *str, char *delim)
{
	char **str_arr;
	char *p;
	int i;

	str_arr = malloc(_strlen(str) + 1024);
	if (str_arr == NULL)
	{
		free(str_arr);
		exit(12);
	}
	i = 0;
	p = _strtok(str, delim);
	while (p != NULL)
	{
		str_arr[i] = _strdup(trim_string(p));
		p = _strtok(NULL, delim);
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}

