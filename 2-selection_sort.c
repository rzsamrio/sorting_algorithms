#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sort
 * @array: Array to sort
 * @size: size of the array to sort
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int pos, tmp, swap;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		swap = 0;
		for (j = i + 1; j < size; j++)
		{
			if (tmp > array[j])
			{
				tmp = array[j];
				pos = j;
				swap = 1;
			}
		}
		if (swap)
		{
			array[pos] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
