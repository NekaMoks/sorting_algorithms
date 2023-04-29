#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - interchange the two integers in array.
 * @a: first integer to interchange.
 * @b: second integer to interchange.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorting integers array in ascending way.
 * @array:  integers array to sort.
 * @size: array size.
 *
 * Description: Display array in each switch.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
