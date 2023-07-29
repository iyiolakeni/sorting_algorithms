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
 * radix_order - Function to sort radix in aascendng order.
 * @arr: Variable for array.
 * @size: Variable for array size.
 * @sdig: Variable for significant digit.
 * @temp: Varaible for temp storage for sorted.
 */
void radix_order(int *arr, size_t size, int sdig, int *temp)
{
	size_t index;
	int num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (index = 0; index < size; index++)
		num[(arr[index] / sdig) % 10] += 1;

	for (index = 0; index < 10; index++)
		num[index] += num[index - 1];

	for (index = size - 1; (int)index >= 0; index--)
	{
		temp[num[(arr[index] / sdig) % 10] - 1] = arr[index];
		num[(arr[index] / sdig) % 10] -= 1;
	}

	for (index = 0; index < size; index++)
		arr[index] = temp[index];
}

/**
 * radix_sort - Function to Perform radix sort.
 * @array: Variable for the array.
 * @size: VAriable for array size.
 *
 * Return: Radix order sorted array.
 */
void radix_sort(int *array, size_t size)
{
	int sdig, *temp, max;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	max = print_max(array, size);

	/*Perform loop for radix sort*/
	for (sdig = 1; max / sdig > 0; sdig *= 10)
	{
		radix_order(array, size, sdig, temp);
		print_array(array, size);
	}

	free(temp);
}
