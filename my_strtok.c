#include "main.h"
#include <string.h>
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
	return (strtok(s, delimiter));
}
