#include "main.h"

/**
 * which - location of command
 * @cmd: command to find its location
 * @globs: global vars
 *
 * Return: string
 */

char *which(char *cmd, glob_t *globs)
{
	char *buffer = malloc(1024);
	paths_t *path_head = globs->path_head;

	if (path_head == NULL)
	{
		free(buffer);
		globs->exitcode = 127;
		return (NULL);
	}
	if (cmd && cmd[0] == '/')
	{
		free(buffer);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		globs->exitcode = 2;
		return (NULL);
	}
	while (cmd && path_head != NULL)
	{
		_strcpy(buffer, "");
		_strcat(buffer, path_head->s);
		_strcat(buffer, "/");
		_strcat(buffer, cmd);
		if (access(buffer, F_OK) == 0)
		{
			return (buffer);
		}
		path_head = path_head->next;
	}
	free(buffer);
	globs->exitcode = 2;
	return (NULL);
}

