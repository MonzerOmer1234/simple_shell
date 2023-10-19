#include "master.h"


int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, int n);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);



/**
 * _strlen - calculates the length of a string
 *
 * @s: the string to get the length of
 *
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int i = 0, length = 0;

	while (s[i++] != '\0')
		length++;

	return (length);
}


/**
 * _strcat - concatenates two strings
 *
 * @dest: the string to be concatenated upon.
 * @src: the source string to be appended to @dest.
 *
 * Return: a pointer to the resulting string @dest.
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0, k, dest_length = 0;

	while (dest[i++] != '\0')
		dest_length++;

	i = dest_length;
	for (k = 0; src[k] != '\0'; k++)
		dest[i++] = src[k];


	dest[i] = '\0';
	return (dest);
}


/**
 * _strncat - concatenates two strings using at most n bytes from @src
 *
 * @dest: the string to be concatenated upon.
 * @src: the string to be appended to @dest.
 * @n: The number of bytes from src to be appended to @dest.
 *
 * Return: the resulting string @dest.
 */
char *_strncat(char *dest, const char *src, int n)
{
	int i = 0, j, dest_length = 0;

	while (dest[i++] != '\0')
		dest_length++;

	i = dest_length;
	for (j = 0; (src[j] != '\0') && (j < n); j++)
		dest[i++] = src[j];

	return (dest);
}


/**
 * _strcmp - compares two strings.
 *
 * @s1: a pointer to the first string to be compared.
 * @s2: a pointer to the second string to be compared.
 *
 * Return: If s1 < s2 - the negative difference of the
 *		   first unmatched characters.
 *
 *		   If s1 == s2 - 0.
 *
 *		   If s1 > s2 - the positive difference of the
 *		   first unmatched characters.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}


/**
 * _strncmp - compares two strings, n bytes at most.
 *
 * @s1: a pointer to the first string to be compared.
 * @s2: a pointer to the second string to be compared.
 * @n: bytes.
 *
 * Return: If s1 < s2 - the negative difference of the
 *		   first unmatched characters.
 *
 *		   If s1 == s2 - 0.
 *
 *		   If s1 > s2 - the positive difference of the
 *		   first unmatched characters.
 */
int _strncmp(const char *s1, const char *s2, int n)
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
