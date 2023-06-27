#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail shaker sort.
 * @list: Pointer to a pointer to the head of the list.
 *
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
		}
		if (!swapped)
			break;

		end = start;

		swapped = 0;
		for (; start->prev != end; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to a pointer to the head of the list.
 * @node1: Pointer to the first node to swap.
 * @node2: Pointer to the second node to swap.
 *
 * Return: void.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1, *next1, *next2;

	prev1 = node1->prev;
	next1 = node1->next;
	next2 = node2->next;

	if (prev1 != NULL)
		prev1->next = node2;
	else
		*list = node2;

	if (next2 != NULL)
		next2->prev = node1;

	node2->prev = prev1;
	node2->next = node1;

	node1->prev = node2;
	node1->next = next2;

	if (next1 != NULL)
		next1->prev = node2;

	node2->prev = prev1;
	node2->next = node1;

	node1->prev = node2;
	node1->next = next2;
}
