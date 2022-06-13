#include "sort.h"

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
* insertion_sort_list - sort a list using insertion method
* @list: the list to sort
*
* return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next, *prev, *hold;

	if (list == NULL)
		return;

	curr = *list;
	next = *list;
	while (curr != NULL)
	{
		while (curr->prev != NULL)
		{
			prev = curr->prev;
			hold = prev;
			if (prev->n > curr->n)
				swap_nodes_and_print(prev, curr, list);
			curr = hold;
		}
		curr = next->next;
		next = curr;
	}
}
