#include "sort.h"

/**
 * swapped - Function to perform swap.
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
 * shell_sort - Function to Perfrom shell sort.
 * @array: Variable for array element.
 * @size: Variable for array size.
 *
 * return:Array in shell sorted style.
 */

void shell_sort(int *array, size_t size)
{
	size_t space, arr, time;

	/*Checks if the arrray is empty*/
	if (array == NULL || size < 2)
		return;

	/*performs loop for the space*/
	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	/*performs second loop for space*/

	for (; space >= 1; space /= 3)
	{
		for (arr = space; arr < size; arr++)
		{
			time = arr;

			/*Loop to perfrom when the time is greater thans the space*/
			while (time >= space && array[time - space] > array[time])
			{
				swapped(array + time, array + (time - space));
				time -= space;
			}
		}
		print_array(array, size);
	}
}
