#include "sort.h"

/**
 * bubble_sort - sorts a list of integers using bubble sort
 *
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap two elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}

