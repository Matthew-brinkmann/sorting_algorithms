#include "sort.h"

/**
 * shell_sort - sort an array of integers in ascending
 * order using the shell sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void, no return
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, k;
	int temp;

	if (array == NULL)
		return;
	while (gap < size)
		gap = 3 * gap + 1;
	if (gap >= size)
		gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (k = i; (k >= gap) && (array[k - gap] > temp); k -= gap)
			{
				array[k] = array[k - gap];
			}
			array[k] = temp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
