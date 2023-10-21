#include "main.h"

/**
 * getCommandPath - finds a command in the PATH environment variable.
 *
 * @command: the command to find.
 *
 * Return: if the command is found - a pointer to the command
 *         otherwise - a null pointer
 */
char* getCommandPath(char* command)
{
	char** pathPtr, *pathname;
	Node* head, *dirNode;
	struct stat st;

	pathPtr = getEnvironmentVariable("PATH");
	if (!pathPtr || !*pathPtr)
		return (NULL);

	head = buildPathList(*pathPtr + 5);

	dirNode = head;
	while (dirNode)
	{
		pathname = malloc(length(dirNode->dir) + length(command) + 2);
		if (!pathname)
			return (NULL);

		copyString(pathname, dirNode->dir);
		concatenate(pathname, "/");
		concatenate(pathname, command);

		if (stat(pathname, &st) == 0)
		{
			deallocateList(head);
			return (pathname);
		}

		dirNode = dirNode->next;
		free(pathname);
	}

	deallocateList(head);

	return (NULL);
}

