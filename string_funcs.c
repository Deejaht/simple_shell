#include "main.h"

/**
 * _strlen - calculate string length
 * @str: string to calculate the length
 *
 * Return: Length of string
 */

int _strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _isspace - is char a space
 * @c: character to check
 * Return: 1 if a space, otherwise 0
 */

int _isspace(char c)
{
	char *spaces;
	int i;

	spaces = " \t\r\v\f\n";
	i = 0;

	while (spaces[i] != '\0')
	{
		if (spaces[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * trim_string - trim a string
 * @str: string to trim
 *
 * Return: string
 */

char *trim_string(char *str)
{
	int i;

	i = _strlen(str) - 1;
	while (i >= 0)
	{
		if (_isspace(str[i]))
			i--;
		else
			break;
	}
	str[i + 1] = '\0';
	i = 0;
	while (_isspace(str[i]))
		i++;
	return (&str[i]);
}

/**
 * _putstr - write a string to stdout
 * @str: string
 * Return: void
 */

void _putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

/**
 * _strcmp - compares equality of two strings
 * @s1: string one
 * @s2: string two
 *
 * Return: 0 if equal, otherwise a positive number
 */

int _strcmp(char *s1, char *s2)
{

	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			break;
	}
	return (s1[i] - s2[i]);
}


















