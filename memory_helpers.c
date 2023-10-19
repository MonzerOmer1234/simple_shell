#include "main.h"

/**
 * get_exit_status - Save the last exit code
 *
 * Return: A pointer to the last saved exit code
 */
int *get_exit_status(void)
{
	static int exit_status = EXIT_SUCCESS;

	return (&exit_status);
}



/**
 * copy_to_heap - Copy the environment variable array to the heap
 *
 * Return: On success - 1
 *	   On error - 0
 */
int copy_to_heap(void)
{
	char **new_environment;
	int i = 0;

	while (environ[i])
		i++;

	new_environment = malloc((i + 1) * sizeof(char *));
	if (new_environment == NULL)
		return (0);

	for (i = 0; environ[i]; i++)
		new_environment[i] = _strdup(environ[i]);

	new_environment[i] = NULL;

	environ = new_environment;

	return (1);
}

/**
 * clean - Free an array of pointers
 * @array: The array to be freed
 *
 * Return: void
 */
void clean(char **array)
{
	int i;

	if (array == NULL)
		return;

	for (i = 0; array[i]; i++)
		free(array[i]);

	free(array);
}

/**
 * _realloc - Reallocate memory block using malloc and free
 *	      and copy the content of ptr to the newly allocated space,
 *	      in the range from the start of ptr up to
 *	      the minimum of the old and new sizes.
 *	      If new_size > old_size, the "added" memory
 *	      should not be initialized
 * @ptr: A pointer to the memory previously allocated with a call to malloc:
 *	 "malloc(old_size)"
 * @old_size: The size, in bytes, of the allocated space for ptr
 * @new_size: The size, in bytes, of the new memory block
 *
 * Return: A pointer to the allocated memory,
 *	   if new_size == old_size,do not do anything and return ptr
 *	   If new_size is equal to zero, and ptr is not NULL,
 *	   then the call is equivalent to free(ptr). Return NULL
 *	   If malloc fails, then _realloc returns NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *arr;
	unsigned int i;
	unsigned int copy_size = old_size;

	if (!ptr)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	else if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size < old_size)
	{
		copy_size = new_size;
	}

	arr = malloc(new_size);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < copy_size; i++)
		*(arr + i) = *((char *)ptr + i);

	free(ptr);

	return (arr);
}
