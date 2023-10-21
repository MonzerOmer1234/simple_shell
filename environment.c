#include "main.h"

/**
 * getEnvironmentVariable - Fetches the value of an environment variable
 *
 * @name: The variable's name.
 *
 * Return: NULL if variable does not exist
 *         Pointer to the variable if it exists
 */
char** getEnvironmentVariable(char* name)
{
	int i = 0, len;

	len = length(name);
	while (environ[i])
	{
		if (compareUpTo(name, environ[i], len) == 0)
			return (&environ[i]);
		i++;
	}
	return (NULL);
}
