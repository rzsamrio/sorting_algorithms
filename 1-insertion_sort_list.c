#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a linked list using insertion sort algorithm
 * @list: address of the head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *p_ptr, *ptr;
	int semi_sorted;

	if (list == NULL || *list == NULL)
		return;

	semi_sorted = 1;
	ptr = *list;
	p_ptr = ptr->prev;
	while (ptr)
	{
		if (p_ptr)
		{
			while (p_ptr->prev)
			{
				if (p_ptr->n < p_ptr->prev->n)
				{
					swap_nodes(p_ptr->prev, p_ptr, list);
					semi_sorted = 0;
				}
				else
					break;
			}
		   semi_sorted = 1;
		}
		if (ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
				swap_nodes(ptr, ptr->next, list);
				semi_sorted = 0;
			}
			p_ptr = ptr->prev;
			if (semi_sorted)
				ptr = ptr->next;
		}
		else
			if (semi_sorted)
				break;
	}
}

/**
 * swap_nodes - swaps 2 nodes in a list
 * @current: the current node
 * @next: the next node to swap with
 * @head: address of the head node
 */
void swap_nodes(listint_t *current, listint_t *next, listint_t **head)
{
	if (!current || !next)
		return;

	/* Update pointers for nodes before and after the swapped nodes */
	if (current->prev)
		current->prev->next = next;
	else
		*head = next;
	next->prev = current->prev;
	if (next->next)
		next->next->prev = current;
	current->next = next->next;

	/* Swap connections between the two nodes */
	current->prev = next;
	next->next = current;
	print_list(*head);
}
