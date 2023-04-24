#include "main.h"
/**
 * execline - executes the command
 * @args: argument array
 * @globs: global variables
 *
 * Return: void
 */
void execline(char **args, glob_t *globs)
{
	pid_t child_pid = 0;
	int status, a;
	char *location;

	a = handle_inbuilt(args, globs);
	if (a == 1)
		return;
	location = which(args[0], globs);
	if (location == NULL)
	{
		if (args && args[0] && _strcmp(args[0], "exit") != 0)
			put_cmd_not_found_err(args[0], globs);
		return;
	}
	child_pid = fork();

	if (child_pid == 0)
	{
		execve(location, args, environ);
		exit(-1);
	}
	else if (child_pid > 0)
	{
		if (errno != 0)
			free(location);
		wait(&status);
		globs->exitcode = status / 256;
	}
	else
		exit(1);
}

/**
 * handle_inbuilt - handle inbuilt functions
 * @args: command line args
 * @globs: global vars
 *
 * Return: int
 */
int handle_inbuilt(char **args, glob_t *globs)
{
	if (args && args[0] && _strcmp(args[0], "exit") == 0)
		return (handle_exit(args, globs));
	if (args && args[0] && _strcmp(args[0], "env") == 0 && !args[1])
		return (print_environment(), 1);
	if (args && args[0] && _strcmp(args[0], "unsetenv") == 0 && args[1])
		return (_unsetenv(args[1], globs));
	if (args && args[0] && _strcmp(args[0], "setenv") == 0 && args[1] && args[2])
		return (_setenv(args[1], args[2], globs));
	if (args && args[0] && _strcmp(args[0], "cd") == 0)
		return (change_dir(args, globs));
	return (0);
}

/**
 * _getenv - get the value of environment variable
 * @name: name of the variable
 *
 * Return: string
 */
char *_getenv(char *name)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		char *env_dec = _strdup(environ[i]);
		char *env_name = _strtok(env_dec, "=");

		if (_strcmp(env_name, name) == 0)
		{
			char *env_path = _strdup(_strtok(NULL, "="));

			free(env_dec);
			return (env_path);
		}
		free(env_dec);
		i++;
	}
	return (NULL);
}

/**
 * handle_semicolons - handles semicolon separated commands
 * @commands: buffer holding commands
 * @line: line to split into commands
 *
 * Return: array of commands
 */
char **handle_semicolons(char *commands[], char *line)
{
	int num_commands = 0;
	char *command;

	command = _strtok(line, ";");

	while (command != NULL && num_commands < 20)
	{
		if (!trim_string(command) || command[0] == '\0')
			break;
		commands[num_commands] = command;
		num_commands++;
		command = _strtok(NULL, ";");
	}
	commands[num_commands] = NULL;
	return (commands);
}
