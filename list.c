#include "main.h"

/**
 * insertNewNode - Adds a new node at the end
 *                of a linked list.
 *
 * @head: The adderss of a pointer to the start of the list
 * @dir: The directory stored in the new node
 *
 * Return: If you are poor (insufficient RAM) - NULL.
 *         Otherwise - the address of the new element.
 */
Node* insertNewNode(Node** head, char* dir)
{
	Node* newNode, *endNode;

	newNode = malloc(sizeof(Node));
	if (newNode == NULL)
		return (NULL);

	newNode->dir = dir;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	endNode = *head;
	while (endNode->next != NULL)
		endNode = endNode->next;

	endNode->next = newNode;

	return (newNode);
}

/**
 * deallocateList - releases the memory occupied by a linked list
 *
 * @head: A pointer to the first node in the list
 */
void deallocateList(Node* head)
{
	Node* temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->dir);
		free(head);
		head = temp;
	}
}

/**
 * buildPathList - Builds a linked list of the directories
 *                 in the PATH environment variable.
 *
 * @paths: the value of the PATH environment variable
 *
 * Return: on success - a pointer to the linked list
 *         on failure - a null pointer
 */
Node* buildPathList(char* paths)
{
	char** dirs;
	Node* head = NULL;
	int i = 0;

	dirs = strsplit(paths, ":");
	if (!dirs)
		return (NULL);

	while (dirs[i])
	{
		if (insertNewNode(&head, dirs[i]) == NULL)
		{
			deallocateList(head);
			free(dirs);
			return (NULL);
		}
		i++;
	}

	free(dirs);

	return (head);
}

