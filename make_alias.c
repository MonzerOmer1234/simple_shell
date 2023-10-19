#include "main.h"

/**
 * search_alias - search if the alias is in the aliases list
 * @head: The head of the linked list that needs to be freed
 * @alias: The alias to find
 *
 * Return: If the alias is found - pointer to the alias
 *	   otherwise - NULL
 */
alias_t *search_alias(alias_t **head, char *alias)
{
	while (*head)
	{
		if (_strcmp((*head)->name, alias) == 0)
			return (*head);

		*head = (*head)->next;
	}

	return (NULL);
}

/**
 * create_alias - Add the new alias to the aliases linked list
 * @head: The head of the linked list that needs to be freed
 * @alias: The alias to add
 *
 * Return: void
 */
void create_alias(alias_t **head, char *alias)
{
	alias_t *alias_found;
	char **name_val_arr = split_string(alias, "=");

	alias_found = search_alias(head, name_val_arr[0]);

	if (alias_found)
	{
		free(alias_found->value);
		alias_found->value = _strdup(name_val_arr[1]);
	}
	else
	{
		printf("before %p\n", (void *) head);
		add_alias_end(head, name_val_arr[0], name_val_arr[1]);
		printf("after %p\n", (void *) head);
	}
	clean(name_val_arr);
#include "main.h"

/**
 * search_env - Search for the variable inside the environment
 * @env_var: The variable to search
 *
 * Return: If the variable is found - a copy of its value
 *	   otherwise - a copy of an empty string
 */
char *search_env(char *env_var)
{
	int offset;
	char *value = _getenv(env_var, &offset);

	if (value == NULL)
		return (_strdup(""));
	return (_strdup(value));
}

/**
 * replace_string - Replace an old string with a new one
 * @old_str: a pointer to the old string
 * @new_str: The new string
 *
 * Return: void
 */
void replace_string(char **old_str, char *new_str)
{
	free(*old_str);
	*old_str = new_str;
}

/**
 * search_cmd_expansion - Search for variable expansions
 * @args: The array of arguments
 *
 * Return: void
 */
void search_cmd_expansion(char **args)
{
	pid_t my_pid;
	int i = 0;
	int *exit_code;
	char *str_expansion;

	if (args == NULL)
		return;

	while (args[i])
	{
		if (_strcmp(args[i], "$?") == 0)
		{
			exit_code = get_exit_status();
			str_expansion = _itoa(*exit_code);
			replace_string(args + i, str_expansion);
		}
		else if (_strcmp(args[i], "$$") == 0)
		{
			my_pid = getpid();
			str_expansion = _itoa(my_pid);
			replace_string(args + i, str_expansion);
		}
		else if (_strchr(args[i], '$') == args[i])
		{
			str_expansion = search_env(args[i] + 1);
			replace_string(args + i, str_expansion);
		}
		i++;
	}
}

/**
 * search_comments - Find if a comment is found
 * @args: The array of arguments
 *
 * Return: void
 */
void search_comments(char **args)
{
	int i = 0;

	if (args == NULL)
		return;

	while (args[i])
	{
		if (_strcmp(args[i], "#") == 0 || _strchr(args[i], '#') == args[i])
		{
			free(args[i]);
			args[i] = NULL;
			i++;
			break;
		}
		i++;
	}
	while (args[i])
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
}

/**
 * create_args - Create the arguments list
 * @buff: The buffer to be handled
 *
 * Return: The arguments list
 */
char **create_args(char *buff)
{
	char **args;

	args = split_string(buff, " \n");

	search_comments(args);
	if (args && args[0] == NULL)
	{
		free(args);
		args = NULL;
	}
	else
	{
		search_cmd_expansion(args);
	}
	free(buff);

	return (args);
}}
