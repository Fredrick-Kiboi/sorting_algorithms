#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using Selection sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		/* Swap two elements */
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
