#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 *
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = *list;
	current = sorted->next;

	while (current != NULL)
	{
		temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* Swap the nodes */
			if (current->next != NULL)
				current->next->prev = current->prev;

			current->prev->next = current->next;
			current->next = current->prev;
			current->prev = current->next->prev;

			if (current->prev != NULL)
				current->prev->next = current;

			current->next->prev = current;

			if (current->prev == NULL)
				*list = current;

			/* Print the list after each swap */
			print_list(*list);
		}

		sorted = current;
		current = temp;
	}
}
