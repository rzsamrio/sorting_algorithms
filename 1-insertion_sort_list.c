#include "sort.h"

/**
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr;
	listint_t *p_ptr;
	int semi_sorted;

	semi_sorted = 1;
	ptr = *list;
	p_ptr = ptr->prev;
	while (ptr)
	{
		if (p_ptr)
		{
			while(p_ptr->prev)
			{
				if (p_ptr->n < p_ptr->prev->n)
					{
						swap_nodes(p_ptr->prev, p_ptr, list);
						print_list(*list);
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
					print_list(*list);
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
}
