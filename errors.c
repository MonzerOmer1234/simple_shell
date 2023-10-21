#include "main.h"

/**
 * errorPermissionDenied - Builds a "permission denied" error message string
 *
 * @args: The command string.
 *
 * Return: Pointer to the error message string.
 */
char* errorPermissionDenied(char** args)
{
	char* errorMessage, *historyString;
	int errorLength;
	char* command = args[0];

	historyString = toString(history);
	if (!historyString)
		return (NULL);

	errorLength = length(program_name) + length(historyString) +
				length(command) + 24;
	errorMessage = malloc(sizeof(char) * (errorLength + 1));
	if (!errorMessage)
	{
		free(historyString);
		return (NULL);
	}

	copyString(errorMessage, program_name);
	concatenate(errorMessage, ": ");
	concatenate(errorMessage, historyString);
	concatenate(errorMessage, ": ");
	concatenate(errorMessage, command);
	concatenate(errorMessage, ": Permission denied\n");

	free(historyString);
	return (errorMessage);
}

/**
 * errorPermissionDenied - Builds a "command not found" error message string
 *
 * @args: The command string.
 *
 * Return: Pointer to the error message string.
 */
char* errorCommandNotFound(char** args)
{
	char* errorMessage, *historyString;
	int errorLength;
	char* command = args[0];

	historyString = toString(history);
	if (!historyString)
		return (NULL);

	errorLength = length(program_name) + length(historyString) +
				length(command) + 16;
	errorMessage = malloc(sizeof(char) * (errorLength + 1));
	if (!errorMessage)
	{
		free(historyString);
		return (NULL);
	}

	copyString(errorMessage, program_name);
	concatenate(errorMessage, ": ");
	concatenate(errorMessage, historyString);
	concatenate(errorMessage, ": ");
	concatenate(errorMessage, command);
	concatenate(errorMessage, ": not found\n");

	free(historyString);
	return (errorMessage);
}

/**
 * errorPermissionDenied - Builds an "illegal number" error message string
 *
 * @args: The command string.
 *
 * Return: Pointer to the error message string.
 */
char* errorIllegalNumberOfArguments(char** args)
{
	char* errorMessage, *historyString;
	int errorLength;
	char* trash = args[1];

	historyString = toString(history);
	if (!historyString)
		return (NULL);

	errorLength = length(program_name) + length(historyString) +
				length(trash) + 27;
	errorMessage = malloc(sizeof(char) * (errorLength + 1));
	if (!errorMessage)
	{
		free(historyString);
		return (NULL);
	}

	copyString(errorMessage, program_name);
	concatenate(errorMessage, ": ");
	concatenate(errorMessage, historyString);
	concatenate(errorMessage, ": exit: Illegal number: ");
	concatenate(errorMessage, trash);
	concatenate(errorMessage, "\n");

	free(historyString);
	return (errorMessage);
}

/**
 * errorEnvironmentAddRemoveFailed - Builds a "could not add or remove environment
 *                                   variable" error message
 *
 * @args: An array of arguments including the command.
 *
 * Return: The error message string.
 */
char* errorEnvironmentAddRemoveFailed(char** args)
{
	char* errorMessage, *historyString;
	int errorLength;
	char* command = args[0];

	historyString = toString(history);
	if (!historyString)
		return (NULL);

	errorLength = length(program_name) + length(historyString) +
				length(command) + 45;
	errorMessage = malloc(sizeof(char) * (errorLength + 1));
	if (!errorMessage)
	{
		free(historyString);
		return (NULL);
	}

	copyString(errorMessage, program_name);
	concatenate(errorMessage, ": ");
	concatenate(errorMessage, historyString);
	concatenate(errorMessage, ": ");
	concatenate(errorMessage, command);
	concatenate(errorMessage, ": Unable to add/remove from environment\n");

	free(historyString);
	return (errorMessage);
}

/**
 * printErrorMessage - trites an error message to stderr.
 *
 * @args: the command string.
 * @err: the error code.
 *
 * Return: the error code.
 */
int printErrorMessage(char** args, int err)
{
	char* errorMessage;

	switch (err)
	{
	case 126:
		errorMessage = errorPermissionDenied(args);
		break;
	case 127:
		errorMessage = errorCommandNotFound(args);
		break;
	case 2:
		errorMessage = errorIllegalNumberOfArguments(args);
		break;
	case 69:
		errorMessage = errorEnvironmentAddRemoveFailed(args);
		break;
	}

	write(STDERR_FILENO, errorMessage, length(errorMessage));

	if (errorMessage)
		free(errorMessage);

	return (err);
}

