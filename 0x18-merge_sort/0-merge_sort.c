#include "sort.h"

/**
 * merge - Merge left and right sub-arrays
 * @arr: Array
 * @lef: Left sub array
 * @rig: Right sub array
 * @size: size of array
 */
void merge(int *arr, int *lef, int *rig, size_t size)
{
	int i = 0, j = 0, k = 0;
	int l = size / 2, r = size - l;

	printf("Merging...\n[left]: ");
	print_array(lef, l);
	printf("[right]: ");
	print_array(rig, r);

	while (i < l && j < r)
	{
		if (lef[i] < rig[j])
			arr[k++] = lef[i++];
		else
			arr[k++] = rig[j++];
	}
	while (i < l)
		arr[k++] = lef[i++];
	while (j < r)
		arr[k++] = rig[j++];
	printf("[Done]: ");
	print_array(arr, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge Sort algorithm
 * @array: Input array
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
	int i, mid = size / 2, left[100], right[100];

	if (!array || size < 2)
		return;

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < (int)size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
