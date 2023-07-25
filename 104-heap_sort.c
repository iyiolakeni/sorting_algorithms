#include "sort.h"


/**
 * swapped - Function to perfrom swap.
 * @i: Variable for first integer.
 * @j: Variable for second integer.
 */

void swapped(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * change_bin_tree - Function to change a binary tree to heap.
 * @arr: Variable for array element in tree.
 * @size: Variable for array size.
 * @low: Variable for lowest in tree.
 * @depth: Variable to tree root.
 */
void change_bin_tree(int *arr, size_t size, size_t low, size_t depth)
{
	size_t start, end, heap;

	start = 2 * depth + 1;
	end = 2 * depth + 2;
	heap = depth;

	if (start < low && arr[start] > arr[heap])
		heap = start;

	if (end < low && arr[end] > arr[heap])
		heap = end;

	if (heap != depth)
	{
		swapped(arr + depth, arr + heap);
		print_array(arr, size);
		change_bin_tree(arr, size, low, heap);
	}
}

/**
 * heap_sort - Function to perfrom heep sort.
 * @array: Variable for array elements.
 * @size: Variable for array size.
 *
 * Description: Prints heaped elements
 */
void heap_sort(int *array, size_t size)
{
	int index;

	if (array == NULL || size < 2)
		return;

	/*Perfor loop for entire heap*/
	for (index = (size / 2) - 1; index >= 0; index--)
		change_bin_tree(array, size, size, index);

	/*Perfrom loop for swapped elements*/
	for (index = size - 1; index > 0; index--)
	{
		swapped(array, array + index);
		print_array(array, size);
		change_bin_tree(array, size, index, 0);
	}
}
