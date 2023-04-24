#include "main.h"

/**
 * put_cmd_not_found_err - write command not found
 * @cmd: command
 * @globs: global vars
 *
 * Return: void
 */
void put_cmd_not_found_err(char *cmd, glob_t *globs)
{
	_puterr(globs->program);
	_puterr(": 1: ");
	_puterr(cmd);
	_puterr(": not found\n");
	errno = 127;
	globs->exitcode = 127;
}
