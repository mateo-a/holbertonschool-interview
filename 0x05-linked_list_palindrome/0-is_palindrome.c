#include "lists.h"

/**
 * is_palindrome - function that checks if a singly linked list is palindrome
 * @head: double pointer to head
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return (1);
	return (chkpal(head, *head));
}

/**
 * chkpal - function to recursively check values of head and tail
 * @head: double pointer to head
 * @tail: single pointer to tail
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int chkpal(listint_t **head, listint_t *tail)
{
	if (tail == NULL)
		return (1);
	if (chkpal(head, tail->next) && (*head)->n == tail->n)
	{
		*head = (*head)->next;
		return (1);
	}
	return (0);
}
