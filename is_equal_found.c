
/**
 * is_equal_found - Search for the equal sign inside the name
 * @name: The variable to check its name
 *
 * Return: If the '=' is found - 1
 *	   otherwise - 0
 */
int is_equal_found(const char *name)
{
	int i = 0;

	for (i = 0; name[i]; i++)
		if (name[i] == '=')
			return (1);
	return (0);
}
