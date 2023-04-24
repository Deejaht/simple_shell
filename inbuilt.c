#include "main.h"

/**
 * print_environment - prints the environment variable
 * @void: no params
 */
void print_environment(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_putstr(environ[i]);
		_putstr("\n");
	}
}

/**
 * handle_exit - handles exit
 * @args: cmd line args
 * @globs: global vars
 *
 * Return: void
 */
int handle_exit(char **args, glob_t *globs)
{
	globs->exit = 1;
	if (_strcmp(args[0], "exit") == 0 && !args[1])
		return (1);
	if (_strcmp(args[0], "exit") == 0 && _atoi(args[1]) != (size_t)INVALID_ATOI)
	{
		globs->exitcode = _atoi(args[1]);
		return (1);
	}
	_puterr(globs->program);
	_puterr(": 1: exit: Illegal number: ");
	_puterr(args[1]);
	_puterr("\n");
	globs->exitcode = 2;
	globs->exit = 0;
	return (1);
}

/**
 * _unsetenv - remove an environment variable
 * @check_str: name of variable to remove
 * @globs: global vars
 *
 * Return: int
 */
int _unsetenv(char *check_str, glob_t *globs)
{
	int a = unsetenv(check_str);

	if (a == -1)
	{
		globs->exitcode = errno;
		perror(globs->program);
	}
	return (1);
}

/**
 * _setenv - add an environment variable
 * @check_name: name of variable to add
 * @check_val: value of variable to add
 * @globs: global vars
 *
 * Return: int
 */
int _setenv(char *check_name, char *check_val, glob_t *globs)
{
	int a = setenv(check_name, check_val, 1);

	if (a == -1)
	{
		globs->exitcode = errno;
		perror(globs->program);
	}
	return (1);
}

/**
 * change_dir - changes the cwd
 * @args: command line args
 * @globs: global vars
 *
 * Return: int
 */
int change_dir(char **args, glob_t *globs)
{
	if (!args[1] || _strcmp(args[1], "~") == 0 ||
		_strcmp(args[1], "$HOME") == 0 || _strcmp(args[1], "--") == 0)
	{
		char *home = _getenv("HOME"), *cwd = _getenv("PWD");

		if (home && chdir(home) == 0)
			return (_setenv("OLDPWD", cwd, globs), _setenv("PWD", home, globs),
					free(home), free(cwd), 1);
		return (free(cwd), 1);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		char *cwd = getcwd(NULL, 0), *oldpwd = _getenv("OLDPWD");

		if (oldpwd && chdir(oldpwd) == 0)
			return (_putstr(oldpwd), _putstr("\n"), _setenv("OLDPWD", cwd, globs),
					_setenv("PWD", oldpwd, globs), free(cwd), free(oldpwd), 1);
		return (_putstr(cwd), _putstr("\n"), free(cwd), 1);
	}
	else
	{
		char *cwd = getcwd(NULL, 0);
		int a = chdir(args[1]);

		if (a == 0)
			return (_setenv("OLDPWD", cwd, globs), _setenv("PWD", args[1], globs),
					free(cwd), 1);
		else
			return (globs->exitcode = errno, _puterr(globs->program),
					_puterr(": 1: cd: can't cd to "), _puterr(args[1]), _puterr("\n"),
					free(cwd), 1);
	}
	return (0);
}
