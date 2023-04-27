#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * switch_ints - switches the two integers in array.
 * @a: first integer to switch.
 * @b: second integer to switch.
 */
void switch_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts the integers array in an ascending way.
 * @array:  integers array to sort.
 * @size: array size.
 * Description: Displays the array in each switch.
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
				switch_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
