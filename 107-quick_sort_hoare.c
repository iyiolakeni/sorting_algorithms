#include "sort.h"

int hoare_divide(int *arr, size_t size, int start, int end);
void hoare_sort(int *arr, size_t size, int start, int end);

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
 * hoare_sort - Function for hoare sort.
 * @arr: Variable for array.
 * @size: Variable for array sizeThe size of the array.
 * @start: Variable for array beginning.
 * @end: Variable for array ending.
 *
 * Return: recursive.
 */
void hoare_sort(int *arr, size_t size, int start, int end)
{
	int div;

	if (end - start > 0)
	{
		div = hoare_divide(arr, size, start, end);
		hoare_sort(arr, size, start, div - 1);
		hoare_sort(arr, size, div, end);
	}
}

/**
 * hoare_divide - Function to divide array
 * @arr: Variable for array.
 * @size: Variable for array sizeThe size of the array.
 * @start: Variable for array beginning.
 * @end: Variable for array ending.
 *
 * Return: Divided array.
 */
int hoare_divide(int *arr, size_t size, int start, int end)
{
	int mid, up, down;

	mid = arr[end];
	for (up = start - 1, down = end + 1; up < down;)
	{
		do {
			up++;
		} while (arr[up] < mid);
		do {
			down--;
		} while (arr[down] > mid);

		if (up < down)
		{
			swapped(arr + up, arr + down);
			print_array(arr, size);
		}
	}

	return (up);
}

/**
 * quick_sort_hoare - Function for quick sort hoare.
 * @array: Variable for array.
 * @size: Variable for array size.
 *
 * Return: Quick sorted.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
