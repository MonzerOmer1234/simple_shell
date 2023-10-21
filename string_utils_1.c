#include "main.h"

/**
 * length - calculates the length of a string
 *
 * Return: the length of the string
 */
int length(const char* s)
{
	int i = 0, length = 0;

	while (s[i++] != '\0')
		length++;

	return (length);
}

/**
 * concatenate - concatenates two strings by appending the source string to the
 *               destination string
 *
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a pointer to the destination string
 */
char* concatenate(char* dest, const char* src)
{
	int i = 0, j, destinationLength = 0;

	while (dest[i++] != '\0')
		destinationLength++;

	i = destinationLength;
	for (j = 0; src[j] != '\0'; j++)
		dest[i++] = src[j];


	dest[i] = '\0';
	return (dest);
}

/**
 * concatenateUpTo - concatenates two strings using up to n characters from
 *                   the source string
 *
 * @dest: the destination string
 * @src: the source string
 * @n: The maximum number of characters to be copied
 *
 * Return: pointer to the destination string
 */
char* concatenateUpTo(char* dest, const char* src, int n)
{
	int i = 0, j, destinationLength = 0;

	while (dest[i++] != '\0')
		destinationLength++;

	i = destinationLength;
	for (j = 0; (src[j] != '\0') && (j < n); j++)
		dest[i++] = src[j];

	return (dest);
}

/**
 * compare - lexicographically compares two strings, @s1 and @s2.
 *
 * Return: If s1 != s2 - the difference between the first two characters
 *                      that differ
 *
 *		   If s1 == s2 - 0.
 */
int compare(const char* s1, const char* s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * compareUpTo - lexicographically compares two strings, @s1 and @s2,
 *               up to the @nth byte
 *
 * Return: If s1 != s2 - the difference between the first two characters
 *                      that differ
 *
 *		   If s1 == s2 - 0.
 */
int compareUpTo(const char* s1, const char* s2, int n)
{
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}

	if (n == 0)
		return (0);
	else
		return (*s1 - *s2);
}

