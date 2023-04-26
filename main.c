#include "main.h"

/**
 * main - entry
 * @argc: number of cli params
 * @argv: array of cli params
 * @envp: array of environment variables
 *
 * Return: always 0
 */

int main(int argc __attribute__((unused)),
		char **argv, char **envp __attribute__((unused)))

{

	glob_t globs;
	int i;
	char *line = NULL, **tokens = NULL, **commands;
	paths_t *path_list = NULL;

	globs.exitcode = 0;
	globs.exit = 0;
	globs.program = argv[0];
	globs.interactive = 1;
	while (1)
	{
		path_list = create_link();
		globs.path_head = path_list;
		if (isatty(STDIN_FILENO) != 0)
			_putstr("<3 ");
		else
			globs.interactive = 0;
		line = _getline(&globs);
		commands = handle_semicolons(globs.col_buffer, line);
		for (i = 0; commands[i] != NULL; i++)
		{
			tokens = slit_string(commands[i], "\n");
			execline(tokens, &globs);
			free_str_arr(tokens);
		}
		free(line);
		free_paths(path_list);
		if (globs.exit == 1)
			exit(globs.exitcode);
	}
	return (0);
}
