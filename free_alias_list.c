#include "main.h"

/**
 * free_list - Free a list_t list
 * @head: A pointer to the linked list to be freed
 *
 * Return: void
 */
void free_list(alias_t *head)
{
	alias_t *tmp;

	while (head)
	{
		tmp = head->next;

		free(head->name);
		free(head->value);
		free(head);
		head = tmp;
	}
}
