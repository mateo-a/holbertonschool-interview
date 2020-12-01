#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index start, assuming
 *             the heaps rooted at its children are valid
 *
 * @array: array
 * @start: start
 * @end: end
 * @size: length of array
 *
 * Return: void
 */

void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;
	int temp;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * heapify - Put elements of array in heap order
 *
 * @array: array
 * @size: length of array
 */

void heapify(int *array, size_t size)
{
	size_t start;

	if ((size - 1) % 2 == 0)
		start = (size - 3) / 2;
	else
		start = (size - 2) / 2;
	while (start + 1 >= 1)
	{
		sift_down(array, start, size - 1, size);
		start -= 1;
	}
}

/**
 * heap_sort - function that sorts an array of integers in ascending order
 *             using the Heap sort
 *
 * @array: array
 * @size: length of array
 *
 */

void heap_sort(int *array, size_t size)
{
	size_t last;
	int base;

	if (size < 2)
		return;
	heapify(array, size);
	last = size - 1;
	while (last > 0)
	{
		base = array[0];
		array[0] = array[last];
		array[last] = base;
		print_array(array, size);
		last -= 1;
		sift_down(array, 0, last, size);
	}
}
