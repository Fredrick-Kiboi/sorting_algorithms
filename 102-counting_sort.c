#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j, count_size;
        int max;
        int *count_array, *sorted_array;

        if (array == NULL || size < 2)
		return;

	max = array[0];

	/* Find the maximum element in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array with size (max + 1) */
	count_size = (size_t)(max + 1);
	count_array = malloc(count_size * sizeof(int));
	if (count_array == NULL)
		return;

	/* Initialize the counting array with zeros */
	for (i = 0; i < count_size; i++)
		count_array[i] = 0;

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Modify the counting array to store the actual position of each element */
	for (i = 1; i < count_size; i++)
		count_array[i] += count_array[i - 1];

	/* Create a sorted array using the counting array */
	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}

	for (j = size - 1; j < size; j--)
	{
		sorted_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]]--;
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	/* Print the counting array */
	print_array(count_array, count_size);

	free(count_array);
	free(sorted_array);
}
