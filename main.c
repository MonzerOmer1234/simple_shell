#include "main.h"

char* program_name;
int history;
int status;
char* prompt;
int prompt_size;

/**
 * main - A simple UNIX command interpreter.
 *
 * @argc: Argument count
 * @argv: Argument values
 *
 * Return: Always 0.
 */
int main(int argc, char** argv)
{
	char** args = NULL;
	int ret = 0;

	UNUSED(argc);

	program_name = argv[0];
	history = 1;
	status = 0;
	prompt = ">>> ";
	prompt_size = length(prompt);
	signal(SIGINT, onCtrlC);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, prompt_size);
		ret = runArgs(&args);
		if (ret == END_OF_FILE)
			exit(status);
	}

	return (status);
}



/**
 * execCommand - Executes a command in a child process.
 *
 * @args: An array of the command with its arguments.
 *
 * Return: If an error occurs - an appropriate error code.
 *         Otherwise - The exit value of the last executed command.
 */
int execCommand(char** args)
{
	pid_t forkPid;
	int ret = 0, allocatedCommand = 0;
	char* command = args[0];

	if (command[0] != '/' && command[0] != '.')
	{
		command = getCommandPath(command);
		allocatedCommand = 1;
	}

	if (!command)
		return (printErrorMessage(args, 127));

	if (access(command, F_OK) == -1)
	{
		if (allocatedCommand)
			free(command);
		return (printErrorMessage(args, 127));
	}

	forkPid = fork();
	if (forkPid == -1) /* fork failed */
	{
		if (allocatedCommand)
			free(command);
		perror("Error child");
		return (1);
	}
	if (forkPid == 0) /* child process */
	{
		if (access(command, X_OK) == -1)
			return (printErrorMessage(args, 126));

		if (execve(command, args, environ) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else /* parent process */
	{
		wait(&status);
		if (allocatedCommand)
			free(command);
		ret = WEXITSTATUS(status);
	}

	return (ret);
}


/**
 * getArgs - Reads and tokenizes arguments from the command line.
 *
 * @args: A pointer to an array to store the tokenized arguments.
 *
 * Return: If tokenization failed - SPLIT_ERROR.
 *		   If EOF was read - END_OF_FILE.
 *         Otherwise, on success - 0.
 */
int getArgs(char*** args)
{
	size_t n = 0;
	ssize_t nread;
	char* line = NULL;

	nread = getline(&line, &n, stdin);
	if (nread == -1 || nread == 1)
		free(line);

	if (nread == 1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, prompt_size);
		history++;
		return (getArgs(args));
	}
	if (nread == -1)
		return (END_OF_FILE);

	line[nread - 1] = '\0';
	*args = strsplit(line, " ");

	free(line);

	if (!*args)
		return (SPLIT_ERROR);

	return (0);
}


/**
 * runArgs - Gets arguments, executes them if required
 *			  and modifies the status.
 *
 * @args: A pointer to an array to store the arguments.
 *
 * Return: If tokenization failed - SPLIT_ERROR.
 *		   If EOF was read - END_OF_FILE.
 *		   If an error occurs - an appropriate error code.
 *         Otherwise - The exit value of the last executed command.
 */
int runArgs(char*** args)
{
	int ret;
	char* command;

	ret = getArgs(args);
	if (ret == SPLIT_ERROR)
		return (SPLIT_ERROR);
	if (ret == END_OF_FILE)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (END_OF_FILE);
	}

	command = *args[0];
	if (!command)
		return (0);

	if (!compare("exit", command))
		status = execExit(*args);
	else if (!compare("env", command))
		status = execEnv(*args);
	else if (!compare("setenv", command))
		status = execSetenv(*args);
	else
		status = execCommand(*args);

	history++;

	deallocateArgs(*args);
	return (status);
}


/**
 * deallocateArgs - Frees up memory taken by an array of arguments.
 *
 * @args: A NULL-terminated array of strings (arguments) to be freed.
 */
void deallocateArgs(char** args)
{
	size_t i = 0;

	if (args)
	{
		while (args[i] != NULL)
			free(args[i++]);
		free(args);
	}
}

