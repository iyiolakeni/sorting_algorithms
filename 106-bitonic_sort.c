#include "sort.h"

void bitonic_recurse(int *arr, size_t size, size_t start, size_t order,
		char dir);
void bitonic_order(int *arr, size_t size, size_t start, size_t order,
		char dir);

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
 * bitonic_order - Function for sorting in tionic order.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @order: Variable for the order to sort.
 * @dir: Variable for sort direction.
 */
void bitonic_order(int *arr, size_t size, size_t start, size_t order, char dir)
{
	char *str = (dir == TOP) ? "UP" : "DOWN";
	size_t divd = order / 2;

	if (order > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", order, size, str);
		print_array(arr + start, order);

		/*Starting from the top*/
		bitonic_order(arr, size, start, divd, TOP);
		/*Starting from the bottom*/
		bitonic_order(arr, size, start + divd, divd, BOTTOM);
		/*Marging of the two together*/
		bitonic_recurse(arr, size, start, divd, dir);

		printf("Result [%lu/%lu] (%s):\n", order, size, str);
		print_array(arr + start, order);
	}
}

/**
 * bitonic_recurse - Sort a bitonic sequence inside an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @order: Variable for the order to sort.
 * @dir: Variable for sort direction.
 */
void bitonic_recurse(int *arr, size_t size, size_t start, size_t order,
		char dir)
{
	size_t i, move = order / 2;

	if (order > 1)
	{
		for (i = start; i < start + move; i++)
		{
			if ((dir == TOP && arr[i] > arr[i + move]) ||
			    (dir == BOTTOM && arr[i] < arr[i + move]))
				swapped(arr + i, arr + i + move);
		}
		bitonic_recurse(arr, size, start, move, dir);
		bitonic_recurse(arr, size, start + move, move, dir);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_order(array, size, 0, size, TOP);
}
