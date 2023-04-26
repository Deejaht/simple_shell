#ifndef _main_h
#define _main_h
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <sys/wait.h>
#include "errno.h"


extern char **environ;
#define INVALID_ATOI -9999999

/**
 * struct paths_s - node of a path
 * @s: path
 * @next: pointer to a next path
 */

typedef struct paths_s
{
	char *s;
	struct paths_s *next;

} paths_t;

/**
 * struct glob_s - global struct
 * @program: program name
 * @location: cmd location
 * @path_head: pointer to head of path list
 * @exitcode: exit code when exit called
 * @interactive: flag to know if program is interactive
 * @exit: flag to know if exit is called
 * @col_buffer: buffers semicolon separated commands
 */

typedef struct glob_s
{
	char *program;
	char *location;
	paths_t *path_head;
	int exitcode;
	int interactive;
	int exit;
	char *col_buffer[10000];
} glob_t;


/* execline.c */
void execline(char **args, glob_t *globs);
int handle_inbuilt(char **args, glob_t *globs);
char *_getenv(char *name);
char **handle_semicolons(char *commands[], char *line);

/* string_funcs.c */
int _strlen(char *s);
int _isspace(char c);
void _putstr(char *str);
char *trim_string(char *str);
int _strcmp(char *s1, char *s2);

/* string_func_two.c */
char *_strcat(char *dest, char *src);
char *_strcpy(char *destination, char *source);
void _puterr(char *str);
size_t _atoi(char *str);

/* getline.c */
char *_getline(glob_t *glob);
size_t my_getline(char **lineptr, size_t *n, int fd);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* split_line.c */
char *_strdup(char *str);
void free_str_arr(char **str_arr);
char **slit_string(char *str, char *delim);

/* my_strtok.c */
char *_strtok(char *s, const char *delimiter);

/* linked_paths */
paths_t *add_node_end(paths_t *head, char *s);
struct paths_s *create_link();
void print_paths(paths_t *head);
void free_paths(paths_t *head);

/* which.c */
char *which(char *cmd, glob_t *globs);

/* errors.c */
void put_cmd_not_found_err(char *cmd, glob_t *globs);

/* inbuilt.c */
void print_environment(void);
int change_dir(char **args, glob_t *globs);
int _unsetenv(char *check_str, glob_t *globs);
int _setenv(char *check_name, char *check_val, glob_t *globs);
int handle_exit(char **args, glob_t *globs);

#endif
