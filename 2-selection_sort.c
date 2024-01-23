#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sort
 * @array: Array to sort
 * @size: size of the array to sort
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
		print_array(array, size);
	}
}
