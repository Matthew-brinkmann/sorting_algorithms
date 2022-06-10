#include "sort.h"

/**
 * selection_sort - sort an array of integers in ascending
 * order using the selection sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void, no return
 */

void selection_sort(int *array, size_t size)
{
	size_t i, i2, min, temp;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (i2 = i + 1; i2 < size; i2++)
		{
			if (array[i2] < array[min])
				min = i2;
		}
		if (i != min)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
