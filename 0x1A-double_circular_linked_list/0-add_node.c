#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_end(List **list, char *str)
{
	List *new = NULL;

	if (!list)
		return (NULL);
	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!(new->str))
		return (NULL);
	if (!*list)
	{
		new->next = new;
		new->prev = new;
		*list = new;
	}
	else
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(new->next)->prev = new;
		(new->prev)->next = new;
	}
	return (new);
}

/**
 * add_node_begin - Adds a new node to the beginning of a
 *					double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_begin(List **list, char *str)
{
	List *new = NULL;

	new = add_node_end(list, str);
	if (!new)
		return (NULL);
	*list = new;
	return (new);
}
