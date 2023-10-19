#include "main.h"

/**
 * _isdigit - Check for a digit.
 * @c: The character to check
 * Return: 1 if c is digit 0 otherwise.
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * is_atoi - Check if a string is convertable to digit
 * @str: The string to check
 *
 * Return: If the string is convertable - 1
 *	   otherwise - 0
 */
int is_atoi(char *str)
{
	while (str)
	{
		if (_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
