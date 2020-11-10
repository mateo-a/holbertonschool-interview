#include "search.h"

/**
 * linear_skip - Function that searches for a value in a sorted skip list
 *               of integers.
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: Pointer on the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i;
	skiplist_t *skip, *hold;

	if (!list)
		return (NULL);

	skip = list, hold = list;

	while (skip && skip->next && (skip->n) < value)
	{
		hold = skip;

		if (skip->express)
		{
			skip = skip->express;

			printf("Value checked at index [%lu] = [%d]\n",
				   skip->index, skip->n);
		}
		else
			while (skip->next)
				skip = skip->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   hold->index, skip->index);

	for (i = hold->index;
		 i <= (skip->index) && (hold->n <= value);
		 i++, hold = hold->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", i, hold->n);
		if (hold && (hold->n) == value)
			return (hold);
	}

	if (hold)
		printf("Value checked at index [%lu] = [%d]\n", i, hold->n);

	return (NULL);
}
