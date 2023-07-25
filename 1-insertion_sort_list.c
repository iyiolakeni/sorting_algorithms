#include "sort.h"

/**
 * swap_dllist - Function to perform swap in doubly-linked list.
 * @head: Variable for pointer to head.
 * @node1: Variable for pointer to first node.
 * @node2: Variable for pointer to second node.
 */
void swap_dllist(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Function that performs insertion sort on
 *						doubly linked list.
 * @list: Varibale for a pointer to the head of list.
 *
 * Return: the swapped list per row.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *loop, *insert;

	/*Checks for NULL being inserted or points to NULL*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/*loops through the entire list and reareanges*/
	for (loop = (*list)->next; loop != NULL; loop = temp)
	{
		temp = loop->next;
		insert = loop->prev;

		/*Perfroms insertion*/
		while (insert != NULL && loop->n < insert->n)
		{
			/*Perform swap on dubly linked list and print*/
			swap_dllist(list, &insert, loop);
			print_list((const listint_t *)*list);
		}
	}
}
