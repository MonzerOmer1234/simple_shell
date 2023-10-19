#include "master.h"


char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, int n);
char *_strdup(char *str);


/**
 * _strchr - Locates a character in a string.
 *
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If @c is found, a pointer to the first occurence.
 *         If @c is not found, NULL.
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);

		i++;
	}

	if (s[i] == c)
		return (s + i);

	return ('\0');
}


/**
 * _strstr - Locates a substring.
 *
 * @haystack: The string to be searched.
 * @needle: The substring to be located.
 *
 * Return: If the substring is located, a pointer to the beginning
 *                                       of the located substring.
 *         If the substring is not located, NULL.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0')
		{
			if (haystack[i + j] != needle[j])
				break;

			j++;
		}

		if (needle[j] == '\0')
			return (haystack + i);

		i++;
	}

	return ('\0');
}


/**
 * _strcpy - copies the string pointed to by src, including the terminating
 *			 null byte (\0), to the buffer pointed to by dest.
 *
 * @src: pointer to the source string
 * @dest: pointer to the destination string
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = -1;

	while (src[++i] != '\0')
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}


/**
 * _strncpy - Copies at most @n number of bytes
 *            from string @src into @dest.
 *
 * @dest: a pointer to the buffer storing the string copy.
 * @src: a pointer to the source string.
 * @n: The maximum number of bytes to be copied from @src.
 *
 * Return: a pointer to the resulting string @dest.
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i = 0, src_length = 0;

	while (src[i++] != '\0')
		src_length++;

	for (i = 0; (src[i] != '\0') && (i < n); i++)
		dest[i] = src[i];

	for (i = src_length; i < n; i++)
		dest[i] = '\0';

	return (dest);
}


/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 *           containing a copy of the string given as parameter.
 *
 * @str: The string to be copied.
 *
 * Return: If str == NULL or you are poor (insufficient RAM) - NULL.
 *         Otherwise - a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	unsigned int str_length, i;
	char *copy;

	if (str == NULL)
		return (NULL);

	str_length = _strlen(str);
	copy = malloc(sizeof(char) * (str_length + 1));

	if (copy == NULL)
		return (NULL);

	for (i = 0; i < str_length; i++)
		copy[i] = str[i];
	copy[str_length] = '\0';

	return (copy);
}
