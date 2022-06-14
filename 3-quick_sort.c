#include "sort.h"
#include <stdio.h>

/**
 * partition - partition array by taking last element as pivot
 * @array: the array to sort
 * @low: index of first element in partition
 * @high: index of last element in partition
 * @size: size of array
 *
 * Return: index of partition
 */

int partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	int swap;
	size_t i = low - 1; /* index of smaller value element */
	size_t j, hold = 0;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap = array[i];
			array[i] = array[j];
			array[j] = swap;
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	i++;
	hold = i;
	swap = array[i];
	array[i] = array[high];
	array[high] = swap;
	if (array[i] != array[j])
		print_array(array, size);

	return (hold);
}

/**
 * quick_sort_recursive - sort an array of integers in ascending order
 * @array: the array to sort
 * @low: index of smallest element
 * @high: index of largest element
 * @size: size of the array
 *
 * Return: void, no return
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition_idx;

	if (low < high)
	{
		partition_idx = partition(array, low, high, size);
		quick_sort_recursive(array, low, partition_idx - 1, size);
		quick_sort_recursive(array, partition_idx + 1, high, size);
	}
}
/**
 * quick_sort - sort an array of integers in ascending order using the
 * quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void, no return
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
