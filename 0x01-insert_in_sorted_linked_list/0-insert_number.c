#include "lists.h"
/**
 * insert_node - fucntion that inserts a number into a sorted singly linked list
 * @head: head of list
 * @number: number to add
 * Return: address of new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *temp;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	temp = *head;
	if(temp != NULL && temp->n < number)
	{
		while(temp->next != NULL && temp->next->n < number)
			temp = temp->next;
		new->next = temp->next;
		temp->next = new;
	}
	else
	{
		new->next = *head;
		*head = new;
	}
	new->n = number;
	return (new);
}
