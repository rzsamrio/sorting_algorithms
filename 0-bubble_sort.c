#include "sort.h"

/**
 * bubble_sort - Sorts an array based on the bubble sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int *bus, *whl, *end, tmp;

	bus = &array[0]; /* Capture element */
	end = &array[size]; /* Last Element */
	whl = bus + 1;

	while (whl != bus)
	{
		while (whl < end)
		{
			if (*bus > *whl)
			{
				tmp = *whl;
				*whl = *bus;
				*bus = tmp;
				bus = whl;
				whl++;
				print_array(array, size);
			}
			else if (*bus < *whl)
			{
				bus = whl;
				whl++;
			}
			else
			{
				bus++;
				whl++;
			}
		}
		end--;
		bus = &array[0];
		whl = bus + 1;
		if (whl == end)
			break;
	}
}
