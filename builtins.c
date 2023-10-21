#include "main.h"

/**
 * execExit - Terminates the shell with the given exit code.
 *
 * @args: An array of arguments containing the exit code.
 *
 * Return: 2 if exit code is invalid, terminates otherwise.
 */
int execExit(char** args)
{
	int i = 0;
	char* arg = args[1];

	if (arg)
	{
		while (arg[i])
		{
			if (!isDigit(arg[i]))
				return (printErrorMessage(args, 2));
			i++;
		}

		status = toInteger(arg);
	}

	deallocateArgs(args);
	exit(status);
}

/**
 * execEnv - Prints environment variables.
 *
 * @args: An array of arguments to the env command (including the command).
 *
 * Return: environment found - 0
 *         environment not found - -1
 */
int execEnv(char** args)
{
	int i = 0;

	UNUSED(args);

	if (!environ)
		return (-1);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], length(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * execSetenv - Sets the varValue of an environment variable
 *              Creates a new variable if it does not exist
 *
 * @args: the command string
 *
 * Return: on success - 0
 *         on failure - 69
 */
int execSetenv(char** args)
{
	char** envVariable = NULL;
	char** newEnvironment;
	char* newVariable;
	char* varName = args[1];
	char* varValue = args[2];
	size_t nameLength, valueLength, envsize = 0;
	int i;

	if (!varName || !varValue)
		return (printErrorMessage(args, 69));

	nameLength = length(varName);
	valueLength = length(varValue);
	newVariable = malloc(nameLength + 1 + valueLength + 1);
	if (!newVariable)
		return (printErrorMessage(args, 69));

	copyString(newVariable, varName);
	concatenate(newVariable, "=");
	concatenate(newVariable, varValue);

	envVariable = getEnvironmentVariable(varName);
	if (envVariable)
	{
		*envVariable = newVariable;
		return (0);
	}

	while (environ[envsize])
		envsize++;

	newEnvironment = malloc(sizeof(char *) * (envsize + 2));
	if (!newEnvironment)
	{
		free(newVariable);
		return (printErrorMessage(args, 69));
	}

	for (i = 0; environ[i]; i++)
		newEnvironment[i] = environ[i];

	environ = newEnvironment;
	environ[i] = newVariable;
	environ[i + 1] = NULL;

	return (0);
}
