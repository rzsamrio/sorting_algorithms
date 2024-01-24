#include "sort.h"

void quick_sort(int *array, size_t size)
{
	size_t pi, i, t_size;
	int tmp, *pivot, swap;

	if (size < 2)
	{
		return;
	}
	pivot = &array[size - 1];
	pi = 0;
	for (i = 0, t_size = 0; i < size; i++)
	{
		swap = 0;
		if (*pivot > array[i])
		{
			tmp = array[pi];
			array[pi] = array[i];
			array[i] = tmp;
			pi++;
			print_array(array, size);
			t_size++;
			swap = 1;
			continue;
		}

		if (i == size - 1)
		{
			tmp = array[pi];
			array[pi] = *pivot;
			*pivot = tmp;
			t_size++;
			swap = 1;
			print_array(array, size);
		}
	}
	pi++;

	if (t_size == size)
		quick_sort(array, size - 1);
	if (pi > 1)
		quick_sort(array, size - pi);
	if (pi <= size - 1)
		quick_sort(&array[pi], size - pi);	
	if (swap)
		print_array(array, size);
}

/*
void sort_partitions(array, size)
{
*/	
