#include "search_algos.h"

/**
 * _print - Prints an array between two boundaries
 *
 * @array: pointer to the first element of the array to print
 * @min: left boundary
 * @max: right boundary
 *
 * Return: void
 */

void _print(int *array, size_t min, size_t max)
{
	printf("Searching in array: ");
	for (; min <= max; min++)
	{
		printf("%i", array[min]);
		if (min < max)
			printf(", ");
	}
	printf("\n");
}

/**
 * sub_Binary - searches for a value
 *
 * @array: pointer to the first element of the array
 * @min: left bound
 * @max: right bound
 * @value: value to search for
 *
 * Return: Index or -1
 */

int sub_Binary(int *array, size_t min, size_t max, int value)
{
	int mid;

	if (min < max)
	{
		_print(array, min, max);
		mid = min + (max - min) / 2;
		if (array[mid] >= value)
			return (sub_Binary(array, min, mid, value));
		return (sub_Binary(array, mid + 1, max, value));
	}
	if (array[min] == value)
		return (min);
	_print(array, min, max);
	return (-1);
}

/**
 * advanced_binary - Finds index of first occurence of value
 *
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 *
 * Return: Index of first occurence or -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	int found;

	if (!array || size == 0)
		return (-1);
	found = sub_Binary(array, 0, size - 1, value);
	return (found);
}
