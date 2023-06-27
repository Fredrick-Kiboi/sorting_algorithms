#include <stdio.h>
#include "sort.h"

/**
 * sift_down - Performs sift-down operation on the heap.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @root: The root index of the subtree to sift down.
 * @end: The end index of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max_child, child;
	int temp;

	while ((child = 2 * root + 1) <= end)
	{
		max_child = child;

		if (child + 1 <= end && array[child + 1] > array[child])
			max_child++;

		if (array[root] < array[max_child])
		{
			temp = array[root];
			array[root] = array[max_child];
			array[max_child] = temp;
			print_array(array, size);
			root = max_child;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_sort - Sorts an array of integers using the Heap sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
