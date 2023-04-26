#include "main.h"

size_t _strspn(const char *s, const char *takes);
char *_strpbrk(const char *s, const char *takes);
char *_strchr(char *str, char c);

/**
 * _strtok - works like strtok
 * @s: string going to be split
 * @delimiter: the delimiteriter
 *
 * Return: split string
 */

char *_strtok(char *s, const char *delimiter)
{
	static char *old_str;
	char *token;

	if (s == NULL)
		s = old_str;
	s += _strspn(s, delimiter);
	if (*s == '\0')
	{
		old_str = s;
		return (NULL);
	}
	token = s;
	s = _strpbrk(token, delimiter);
	if (s == NULL)
		old_str = _strchr(token, '\0');
	else
	{
		*s = '\0';
		old_str = s + 1;
	}
	return (token);
}

/**
 * _strspn - works like strspn
 * @s: string
 * @takes: takes
 *
 * Return: int
 */

size_t _strspn(const char *s, const char *takes)
{
	const char *p, *a;
	size_t count = 0;


	for (p = s; *p != '\0'; ++a)
	{
		for (a = takes; *a != '\0'; ++a)
			if (*p == *a)
			break;
	if (*a == '\0')
		return (count);
	++count;
	}
	return (count);

}

/**
 * _strpbrk - works like strpbrk
 * @s: string
 * @takes: takes
 *
 * Return: int
 */

char *_strpbrk(const char *s, const char *takes)
{
	while (*s != '\0')
	{
		const char *a = takes;

		while (*a != '\0')
			if (*a++ == *s)
				return ((char *)s);
		++s;

	}
	return (NULL);
}

/**
 * _strchr - workd line strchr
 * @str: string
 * @c: takes
 *
 * Return: int
 */

char *_strchr(char *str, char c)
{
	char *p = str;

	do {
		if (*p == c)
			return (p);
	} while (*p++);
	return (NULL);
}
