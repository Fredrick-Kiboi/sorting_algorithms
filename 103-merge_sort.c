#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array.
 * @array: The array to merge.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	size_t merged_size = left_size + right_size;
	int *merged_array = malloc(merged_size * sizeof(int));

	if (merged_array == NULL)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			merged_array[k] = left[i];
			i++;
		}
		else
		{
			merged_array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		merged_array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		merged_array[k] = right[j];
		j++;
		k++;
	}

	for (i = 0; i < merged_size; i++)
		array[i] = merged_array[i];

	printf("[Done]: ");
	print_array(array, merged_size);

	free(merged_array);
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	if (size > 1)
	{
		size_t mid = size / 2;
		size_t left_size = mid;
		size_t right_size = size - mid;
		int *left = array;
		int *right = array + mid;

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		merge(array, left, left_size, right, right_size);
	}
}
