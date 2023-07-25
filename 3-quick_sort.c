#include "sort.h"

/**
 * sort_lomuto - Function thatuses recursion for sort.
 * @arr: Variable for the array.
 * @size: Variable for the size.
 * @start: Variable for array start index in partition.
 * @end: Variable for array end index in partition.
 *
 * Return: sorted partition.
 */

void sort_lomuto(int *arr, size_t size, int start, int end)
{
	int index_part;

	/*Checks the start and end index is  greater*/
	if (end - start > 0)
	{
		index_part = part_lomuto(arr, size, start, end);

		/*Performs recursion*/
		sort_lomuto(arr, size, start, index_part - 1);
		sort_lomuto(arr, size, index_part + 1, end);
	}
}


/**
 * part_lomuto - Function for for lomoto partition scheme.
 * @arr: Variable for array.
 * @size: Variable for arry size.
 * @start: Variable for partition starting element.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int part_lomuto(int *arr, size_t size, int start, int end)
{
	int *last_ele, top, bottom;

	last_ele = arr + end;

	/*Loop to check for the pivot element*/
	for (top = bottom = start; bottom < end; bottom++)
	{
		if (arr[bottom] < *last_ele)
		{
			if (top < bottom)
			{
				/*Performs the swap and prints*/
				swapped(arr + bottom, arr + top);
				print_array(arr, size);
			}
			top++;
		}
	}

	/*Checks if the top element in the array is greater*/

	if (arr[top] > *last_ele)
	{
		swapped(arr + top, last_ele);
		print_array(arr, size);
	}

	return (top);
}

/**
 * quick_sort - Funtion to implement quick sort.
 * @array: Variable for array elements.
 * @size: Variable for array size.
 *
 * Return: Quick sorted elements
 */
void quick_sort(int *array, size_t size)
{
	/*Checks content of array elements*/
	if (array == NULL || size < 2)
		return;

	/*Performs the partioning for the quick sort*/
	sort_lomuto(array, size, 0, size - 1);
}
