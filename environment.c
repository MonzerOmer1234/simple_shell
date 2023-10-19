#include "main.h"

/**
 * delete_var - Delete a variable from the environment
 * @offset: The variable's offset
 *
 * Return: On success - 0
 *	   on error - -1
 */
int delete_var(int offset)
{
	char **new_environment, *temp_var;
	int i = 0, count = 0;

	while (environ[count])
		count++;

	new_environment = malloc(count * sizeof(char *));
	if (new_environment == NULL)
		return (-1);

	while (i < offset)
	{
		new_environment[i] = environ[i];
		i++;
	}

	temp_var = environ[offset];

	while (environ[i])
	{
		new_environment[i] = environ[i + 1];
		i++;
	}

	free(temp_var);
	free(environ);

	environ = new_environment;
	return (0);
}

/**
 * _setenv - Add or modify an environment variable
 * @name: The name of the variable to add or modify
 * @value: The value to assign to the variable
 * @overwrite: If the variable is present in the environment variable
 *	       and this member is not zero the variable will be updated
 *
 * Return: On success - 0
 *	   On error - -1
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_var, *env_var, **new_environment = NULL;
	int offset;
	int count = 0;

	if (name == NULL || value == NULL || is_equal_found(name))
		return (-1);

	env_var = _getenv(name, &offset);
	if ((env_var && !overwrite) || (env_var && _strcmp(env_var, value) == 0))
		return (0);

	while (environ[count])
		count++;

	new_var = cat_with_delimiter(name, "=", value);
	if (new_var == NULL)
		return (-1);

	if (env_var)
	{
		free(environ[offset]);
		environ[offset] = new_var;
	}
	else
	{
		new_environment = realloc(environ, ((count + 2) * sizeof(char *)));
		if (new_environment == NULL)
		{
			free(new_var);
			return (-1);
		}
		new_environment[count] = new_var;
		new_environment[count + 1] = NULL;
		environ = new_environment;
	}
	return (0);
}

/**
 * _unsetenv - Delete a a variable from the environment variable
 * @name: The name of the variable to delete
 *
 * Return: On success - 0
 *	   On error - -1
 */
int _unsetenv(const char *name)
{
	char *env_var;
	int offset;

	if (name == NULL || is_equal_found(name))
		return (-1);

	env_var = _getenv(name, &offset);

	if (env_var == NULL)
		return (0);


	delete_var(offset);

	return (0);
}

/**
 * print_env - print the current environment
 *
 * Return: void
 */
void print_env(void)
{
	int i = 0;

	for (i = 0; environ && environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
