#include "master.h"


char **_getenv(char *name);
/*int _unsetenv(char *name);*/


/**
 * _getenv - Gets an environment variable.
 *
 * @name: The name of the environment variable to get.
 *
 * Return: If the environment variable does not exist - NULL.
 *         Otherwise - a pointer to the environment variable.
 */
char **_getenv(char *name)
{
	int count  = 0, len;

	len = _strlen(name);
	while (environ[count])
	{
		if (_strncmp(name, environ[count], len) == 0)
			return (&environ[count]);
		i++;
	}
	return (NULL);
}
