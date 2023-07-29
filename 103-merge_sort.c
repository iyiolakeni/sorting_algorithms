#include "sort.h"

/**
 * merge_recurse - Function to perform recursion.
 * @miniarr: Variable for half of the array.
 * @temp: Varieble for temp storaged for sorted.
 * @start: Variable for begining of the miniarr..
 * @end: Variable for end of miniarr.
 */
void merge_recurse(int *miniarr, int *temp, size_t start, size_t end)
{
	size_t half;

	/*Checks if the difference bettween the start and end > 1*/
	if (end - start > 1)
	{
		half = start + (end - start) / 2;
		merge_recurse(miniarr, temp, start, half);
		merge_recurse(miniarr, temp, half, end);
		merge_subarr(miniarr, temp, start, half, end);
	}
}

/**
 * merge_miniarr - Function to sort a miniarr elements.
 * @miniarr: Variable for miniarr.
 * @temp: Vaiable for temp storage for sorted.
 * @start: Variable for start of the miniarr.
 * @half: Variable for half of the array.
 * @end: Vaiable for the end of array.
 */
void merge_miniarr(int *miniarr, int *temp, size_t start, size_t half,
		size_t end)
{
	size_t x, y;
	size_t z = 0;

	printf("Merging...\n[left]: ");
	print_array(miniarr + start, half - start);

	printf("[right]: ");
	print_array(miniarr + half, end - half);

	/*loops to merge first and second half*/
	for (x = start, y = half; x < half && y < end; z++)
		temp[z] = (miniarr[x] < miniarr[y]) ? miniarr[x++] : miniarr[y++];
	for (; x < half; x++)
		temp[z++] = miniarr[x];
	for (; y < end; y++)
		temp[z++] = miniarr[y];
	for (x = start, z = 0; x < end; x++)
		miniarr[x] = temp[z++];

	printf("[Done]: ");
	print_array(miniarr + start, end - start);
}

/**
 * merge_sort - Function to perfrom merge sort
 * @array: Variable for the array.
 * @size: Variable for the array size.
 *
 * Return: merged sort.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_recurse(array, temp, 0, size);
	free(temp);
}
