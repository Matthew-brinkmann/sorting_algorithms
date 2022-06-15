#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - merging the arrays
 * @array: the array to merge
 * @left: leftmost value of array
 * @right: rightmost value of array
 * @middle: middle value of array
 *
 * Return: void, no return
 */

void merge(int *array, size_t left, size_t middle, size_t right)
{
	int idx_left, idx_right, idx_merge;
	int left_arr_size = middle - left + 1;
	int right_arr_size = right - middle;
	int left_array[4096], right_array[4096];

	printf("Merging...\n");
	for (idx_left = 0; idx_left < left_arr_size; idx_left++)
		left_array[idx_left] = array[left + idx_left];
	for (idx_right = 0; idx_right < right_arr_size; idx_right++)
		right_array[idx_right] = array[middle + 1 + idx_right];

	printf("[left]: ");
	print_array(left_array, left_arr_size);
	printf("[right]: ");
	print_array(right_array, right_arr_size);

	idx_left = idx_right = 0;
	idx_merge = left;
	while (idx_left < left_arr_size && idx_right < right_arr_size)
	{
		if (left_array[idx_left] <= right_array[idx_right])
			array[idx_merge] = left_array[idx_left], idx_left++;
		else
			array[idx_merge] = right_array[idx_right], idx_right++;
		idx_merge++;
	}

	for (; idx_left < left_arr_size; idx_left++, idx_merge++)
		array[idx_merge] = left_array[idx_left];
	for (; idx_right < right_arr_size; idx_right++, idx_merge++)
		array[idx_merge] = right_array[idx_right];
	printf("[Done]: ");
	for (idx_left = left; idx_left <= (int)right; idx_left++)
	{
		printf("%d", array[idx_left]);
		if (idx_left != (int)right)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * merge_sort_recursive - sorting the arrays
 * @array: the array to merge
 * @left: leftmost value of array
 * @right: rightmost value of array
 *
 * Return: void, no return
 */

void merge_sort_recursive(int *array, size_t left, size_t right)
{
	size_t middle;

	if (left < right)
	{
		middle = (left + (right - 1)) / 2;
		merge_sort_recursive(array, left, middle);
		merge_sort_recursive(array, middle + 1, right);

		merge(array, left, middle, right);
	}
}

/**
 * merge_sort - sort an array of integers in ascending order using the merge
 * sort algorithm, using the top-down merge sort algorith
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: void, no return
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}
