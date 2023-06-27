#ifndef SORT_H
#define SORT_H
#include <stddef.h>


/**
 * struct listint_s - Represents a doubly linked list node.
 * @n: Integer stored in the node.
 * @prev: Pointer to the previous element of the list.
 * @next: Pointer to the next element of the list.
 */
typedef struct listint_s
{
	/* Integer stored in the node. */
	const int n;
	/* Pointer to the previous element of the list. */
	struct listint_s *prev;
	/* Pointer to the next element of the list. */
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);

#endif /* SORT_H */