#include "sort.h"

/**
 * bubble_sort - sort an array of integers using bubble sort method
 * @array: the array to sort
 * @size:  the size of the array
 *
 * Description: function to sort an array of intergers in ascending
 * order using the Bubble Sort algorithm
 *
 * Return: void, no return
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, i2;
	int temp;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (i2 = 0; i2 < size - i - 1; i2++)
		{
			if (array[i2] > array[i2 + 1])
			{
				temp = array[i2];
				array[i2] = array[i2 + 1];
				array[i2 + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
