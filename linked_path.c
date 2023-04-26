#include "main.h"

/**
 * add_node_end - add node to end of path
 * @head: head of list
 * @s: string to add
 *
 * Return: paths_t
 */

paths_t *add_node_end(paths_t *head, char *s)

{
	paths_t *temp = head;
	paths_t *new_node = malloc(sizeof(paths_t));

	if (new_node == NULL)
		exit(-1);
	new_node->s = _strdup(s);
	new_node->next = NULL;
	if (head == NULL)
		head = new_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	return (head);

}

/**
 * create_links - create path singly linked list
 *
 * Return: paths_t
 */
struct paths_s *create_links()
{
	int i = 0;
	struct paths_s *head = NULL;
	char *p = NULL, *whole_path = NULL, *attached_path = NULL;

	if (environ == NULL)
		return (NULL);
	for (i = 0; environ && environ[i] != NULL; i++)
	{
		char *path_test;
		
		whole_path = _strdup(environ[i]);
		path_test = _strtok(whole_path, "=");
		attached_path = _strtok(NULL, "=");
		p = _strtok(attached_path, ":");
		if (_strcmp(path_test, "PATH") == 0)
		{
			while (p != NULL)
			{
				head = add_node_end(head, p);
				p = _strtok(NULL, ":");
			}
			free(whole_path);
			break;
		}
		free(whole_path);
	}
	return (head);
}


/**
 * print_paths - print the paths
 * @head: head of the list
 */

void print_paths(paths_t *head)
{
	paths_t *temp = head;

	while (temp && temp->next != NULL)
	{
		_putstr(temp->s);
		_putstr("\n");
		temp = temp->next;
	}
}

/**
 * free_paths - free paths
 * @head: head of list
 */

void free_paths(paths_t *head)
{
	paths_t *temp = head;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->s);
		free(temp);
	}
}
