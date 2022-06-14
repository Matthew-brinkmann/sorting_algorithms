#include "sort.h"
#include <stdio.h>
#define TRUE 1
#define FALSE 0

/**
* swap_nodes_and_print - Swaps two nodes
* @node1: first node to swap
* @node2: second node to swap
* @head: Head of list
*
* return: void
*/
void swap_nodes_and_print(listint_t *node1, listint_t *node2, listint_t **head)
{
	listint_t *temp;

	temp = node1->prev;
	if (temp != NULL)
		temp->next = node2;

	node2->prev = temp;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev == NULL)
		*head = node2;
	print_list(*head);
}

/**
* cocktail_sort_list - sort a list using cocktail method
* @list: the list to sort
*
* return: void
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *search;
	int swapOccured = TRUE;

	if (list == NULL)
		return;

	search = *list;

	while (swapOccured == TRUE)
	{
		swapOccured = FALSE;
		while (search->next != NULL)
		{
			if (search->n > search->next->n)
			{
				swap_nodes_and_print(search, search->next, list);
				swapOccured = TRUE;
			}
			else
			{
				search = search->next;
			}
		}
		if (swapOccured == FALSE)
			break;
		swapOccured = FALSE;
		while (search->prev != NULL)
		{
			if (search->prev->n > search->n)
			{
				swap_nodes_and_print(search->prev, search, list);
				swapOccured = TRUE;
			}
			else
			{
				search = search->prev;
			}
		}
	}
}
