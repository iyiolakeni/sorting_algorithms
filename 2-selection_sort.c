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
 * selection_sort - Function that performs selection sort on an array
 * @array: Variable for array.
 * @size: Variable for array size.
 *
 * Return: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t arr, tim;
	int *least;

	/*Checks if the array is NULL or has items less then 2*/
	if (array == NULL || size < 2)
		return;

	/*Loops through the entire array*/

	for (arr = 0; arr < size - 1; arr++)
	{
		least = array + arr;
		/*Loops to through the array to swap*/
		for (tim = arr + 1; tim < size; tim++)
			least = (array[tim] < *least) ? (array + tim) : least;

		/*Checks if value is not the least and swaps*/
		if ((array + arr) != least)
		{
			swapped(array + arr, least);
			print_array(array, size);
		}
	}
}
