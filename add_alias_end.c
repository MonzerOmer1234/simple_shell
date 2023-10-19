#include "main.h"

/**
 * add_alias_end - Add a new alias at the end of an aliases linked list
 * @head: A pointer to a pointer to the first node in the linked list
 * @name: The name of the alias to put inside the node
 * @value: The value of the alias to put inside the node
 *
 * Return: A pointer to the new node in the linked list
 */
alias_t *add_alias_end(alias_t **head, const char *name, const char *value)
{
	alias_t *new;
	alias_t *tail = *head;

	new = malloc(sizeof(alias_t));

	if (!new)
		return (NULL);

	new->name = _strdup(name);
	new->value = _strdup(value);

	if (!(new->name) || !(new->value))
	{
		free(new);
		return (NULL);
	}


	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	while (tail->next)
		tail = tail->next;

	tail->next = new;

	return (new);
}
