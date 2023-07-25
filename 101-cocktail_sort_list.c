#include "sort.h"


/**
 * swap_front_node - Function to swap node at the front.
 * @head: Variable for head of list.
 * @end: Variable for end of list.
 * @curr_swap: variable for current swapping node.
 */
void swap_front_node(listint_t **head, listint_t **end, listint_t **curr_swap)
{
	listint_t *temp_node = (*curr_swap)->next;

	if ((*curr_swap)->prev != NULL)
		(*curr_swap)->prev->next = temp_node;
	else
		*head = temp_node;

	temp_node->prev = (*curr_swap)->prev;
	(*curr_swap)->next = temp_node->next;

	if (temp_node->next != NULL)
		temp_node->next->prev = *curr_swap;
	else
		*end = *curr_swap;

	(*curr_swap)->prev = temp_node;
	temp_node->next = *curr_swap;
	*curr_swap = temp_node;
}

/**
 * swap_end_node - Function to swap a node at end in a list.
 * @head: Variable for head of list.
 * @end: Variable for end of list.
 * @curr_swap: variable for current swapping node.
 */

void swap_end_node(listint_t **head, listint_t **end, listint_t **curr_swap)
{
	listint_t *temp_node = (*curr_swap)->prev;

	if ((*curr_swap)->next != NULL)
		(*curr_swap)->next->prev = temp_node;
	else
		*end = temp_node;
	temp_node->next = (*curr_swap)->next;
	(*curr_swap)->prev = temp_node->prev;
	if (temp_node->prev != NULL)
		temp_node->prev->next = *curr_swap;
	else
		*head = *curr_swap;
	(*curr_swap)->next = temp_node;
	temp_node->prev = *curr_swap;
	*curr_swap = temp_node;
}

/**
 * cocktail_sort_list - Function to perfrom the corktail sort.
 * @list: Variable to head of list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail_node, *curr_swap;
	bool_t temp_node = false;

	/*Check for empty list*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail_node = *list; tail_node->next != NULL;)
		tail_node = tail_node->next;

	while (temp_node == false)
	{
		temp_node = true;
		/*Perfroms loop for elements in the front node*/
		for (curr_swap = *list; curr_swap != tail_node; curr_swap = curr_swap->next)
		{
			if (curr_swap->n > curr_swap->next->n)
			{
				swap_front_node(list, &tail_node, &curr_swap);
				print_list((const listint_t *)*list);
				temp_node = false;
			}
		}
		/*Performs loop for elements in the end node*/
		for (curr_swap = curr_swap->prev; curr_swap != *list;
				curr_swap = curr_swap->prev)
		{
			if (curr_swap->n < curr_swap->prev->n)
			{
				swap_end_node(list, &tail_node, &curr_swap);
				print_list((const listint_t *)*list);
				temp_node = false;
			}
		}
	}
}
