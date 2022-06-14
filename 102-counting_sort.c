#include <stdlib.h>
#include "sort.h"

/**
 * find_max_val_in_array - finds the maximum value in an array
 * @array: the arry to search
 * @size: size of the array
 * Return: the maximum value in the array
 */
int find_max_val_in_array(int *array, size_t size)
{
	int maxNumber = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > maxNumber)
			maxNumber = array[i];
	}

	return (maxNumber);
}

/**
 * counting_sort - sorts array using counting sort method
 * @array: the arry to search
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int maxValue = 0, *count, *output, i;

	if (array == NULL || size < 2)
		return;

	maxValue = find_max_val_in_array(array, size);
	count = malloc(sizeof(int) * ((int)maxValue + 1));
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
		return;
	for (i = 0; i < (int)size; i++)
	{
		count[array[i]] += 1;
	}
	for (i = 1; i <= maxValue; ++i)
	{
		count[i] += count[i - 1];
	}
	print_array(count, maxValue + 1);
	for (i = 0; i < (int)size; ++i)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}
}
