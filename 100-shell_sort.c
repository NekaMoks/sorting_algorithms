#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * switch_ints - Switches two integers in an array.
 * @a: The first integer to be switched.
 * @b: The second integer to be switched.
 */
void switch_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: Array Size.
 * Description: Makes use of the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				switch_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
