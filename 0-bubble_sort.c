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
 * bubble_sort - Function to sort array using bubble.
 * @array: Variable for the array.
 * @size: Variable for array size.
 *
 * Return: Void type.
 */
void bubble_sort(int *array, size_t size)
{
	bool_t b_sort = false;
	size_t t, arr = size;

	if (array == NULL || size < 2)
		return;

	while (b_sort == false)
	{
		b_sort = true;
		/*Goes though the array */
		for (t = 0; t < arr - 1; t++)
		{
			if (array[t] > array[t + 1])
			{
				/*Perform the swapp and then print*/
				swapped(array + t, array + t + 1);
				print_array(array, size);
				/*then it is false*/
				b_sort = false;
			}
		}
		arr--;
	}
}
