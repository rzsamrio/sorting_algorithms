#include "sort.h"
/**
 * bubble_sort - Sorts an array based on the bubble sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int *bus, *whl, *end, tmp;

	if (size < 2)
		return;
	bus = &array[0]; /* set bus to first element */
	end = &array[size]; /* specify end */
	whl = bus + 1; /* set wheels to next element */

	while (whl != bus)	/* While there's space for motion */
	{
		while (whl < end)
		{
			if (*bus > *whl)	/* Swap weights if bus is heavier than wheel */
			{
				tmp = *whl;
				*whl = *bus;
				*bus = tmp;
				bus = whl;
				whl++;
				print_array(array, size);
			}
			else /* Else keep moving */
			{
				bus++;
				whl++;
			}
		}
		/*
		 * Restrict path after every iteration
		 * Locks the sorted set
		 */
		end--;
		bus = &array[0]; /* Restart conditions */
		whl = bus + 1;
		if (whl == end || bus == end)	/* End conditions */
			break;
	}
}
