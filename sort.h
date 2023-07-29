#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

#define TOP 0
#define BOTTOM 1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool_s - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool_s
{
	false = 0,
	true
} bool_t;



/* Sorting algoritms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/*Swap and helper functions*/
void swapped(int *i, int *j);
void sort_lomuto(int *arr, size_t size, int start, int end);
int part_lomuto(int *arr, size_t size, int start, int end);
void swap_front_node(listint_t **head, listint_t **end, listint_t **curr_swap);
void swap_end_node(listint_t **head, listint_t **end, listint_t **curr_swap);
int print_max(int *arr, int size);
void change_bin_tree(int *arr, size_t size, size_t low, size_t depth);
void merge_miniarr(int *miniarr, int *temp, size_t start, size_t half,
		size_t end);
void merge_recurse(int *miniarr, int *temp, size_t start, size_t end);
void radix_order(int *arr, size_t size, int sdig, int *temp);

/* Print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */
