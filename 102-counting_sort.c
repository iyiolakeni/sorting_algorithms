#include "sort.h"

/**
 * print_max - Function to print max element in an array.
 * @arr: Variable for array elements.
 * @size: Variable for array size.
 *
 * Return: Array's maximum element.
 */
int print_max(int *arr, int size)
{
	int max_ele, index;

	for (max_ele = arr[0], index = 1; index < size; index++)
	{
		if (arr[index] > max_ele)
			max_ele = arr[index];
	}

	return (max_ele);
}

/**
 * counting_sort - Function for coouting sort.
 * @array: Variable for array elements.
 * @size: Variable for array size.
 *
 * Return: Counting array.
 */

void counting_sort(int *array, size_t size)
{
	int *num, *temp, max_ele, index;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	max_ele = print_max(array, size);
	num = malloc(sizeof(int) * (max_ele + 1));

	if (num == NULL)
	{
		free(temp);
		return;
	}

	for (index = 0; index < (max_ele + 1); index++)
		num[index] = 0;

	for (index = 0; index < (int)size; index++)
		num[array[index]] += 1;

	for (index = 0; index < (max_ele + 1); index++)
		num[index] += num[index - 1];

	print_array(num, max_ele + 1);

	for (index = 0; index < (int)size; index++)
	{
		temp[num[array[index]] - 1] = array[index];
		num[array[index]] -= 1;
	}

	for (index = 0; index < (int)size; index++)
		array[index] = temp[index];

	free(temp);
	free(num);
}
