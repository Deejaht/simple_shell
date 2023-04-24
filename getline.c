#include "main.h"

/**
 * _realloc - reallocates malloc'd size
 * @ptr: pointer to old block
 * @old_size: old size
 * @new_size: new size
 *
 * Return: pointer to new block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i = 0;
	char *newPtr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		newPtr = malloc(new_size);
		if (!newPtr)
			return (NULL);
	}
	if (new_size == 0 && ptr != NULL)
		return (free(ptr), NULL);
	if (new_size > old_size && (ptr != NULL))
	{
		newPtr = malloc(new_size);
		if (!newPtr)
			return (NULL);
		for (i = 0; i < old_size; i++)
			newPtr[i] = ((char *)ptr)[i];
		free(ptr);
	}
	return (newPtr);
}

/**
 * my_getline - implements getline
 * @lineptr: pointer to buffer that holds read line
 * @n: space to allocate
 * @fd: file descriptor
 *
 * Return: number of bytes read
 */
size_t my_getline(char **lineptr, size_t *n, int fd)
{
	int num_read = 0;
	size_t total_read = 0;
	char *buf = NULL, ch = '\0';

	if (lineptr == NULL || n == NULL)
		return (-1);
	buf = (char *)malloc(*n);
	while (1)
	{
		num_read = read(fd, &ch, 1);
		if (num_read == -1 || num_read == 0)
			break;
		if (total_read >= *n)
		{
			unsigned int new_size = *n + 128;

			buf = (char *)_realloc(buf, *n, new_size);
			*n += 128;
		}
		buf[total_read++] = ch;
		if (ch == '\n')
			break;
	}
	if (total_read == 0)
		return (free(buf), -1);
	buf[total_read] = '\0';
	*lineptr = buf;
	return (total_read);
}

/**
 * _getline - get a line
 * @glob: global params
 *
 * Return: gotten line
 */
char *_getline(glob_t *glob)
{
	size_t num = 0;
	ssize_t bytes_read = 0;
	char *buf = NULL;

	errno = 0;
	bytes_read = my_getline(&buf, &num, 0);
	if (bytes_read == -1)
	{
		if (errno)
			perror(glob->program);
		if (glob->path_head != NULL)
			free_paths(glob->path_head);
		free(buf);
		exit(glob->exitcode);
	}
	return (buf);
}
