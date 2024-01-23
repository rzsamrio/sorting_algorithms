#include "sort.h"
#include <stdio.h>
/**
 *
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
	}
}
