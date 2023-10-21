#include "main.h"

/**
 * getDigitCount - Calculates the number of digits in an integer.
 */
int getDigitCount(int n)
{
	unsigned int num;
	int len = 1;

	if (n < 0)
	{
		num = n * -1;
		len++;
	}
	else
	{
		num = n;
	}

	while (num >= 10)
	{
		num /= 10;
		len++;
	}

	return (len);
}

/**
 * toString - Converts an integer to a string.
 */
char* toString(int n)
{
	unsigned int num;
	int len = getDigitCount(n);
	char* str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	if (n < 0)
	{
		num = n * -1;
		str[0] = '-';
	}
	else
	{
		num = n;
	}

	str[len] = '\0';

	len--;
	do {
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	} while (num > 0);

	return (str);
}

/**
 * toInteger - Convert a string to an integer
 */
int toInteger(char* str)
{
	int sign = 1, digit;
	unsigned int number = 0;
	char chr = *str;

	while (chr != '\0')
	{
		if (chr == '-')
		{
			sign *= -1;
		}
		else if (chr >= '0' && chr <= '9')
		{
			digit = chr - '0';
			number = number * 10 + digit;
		}
		else if (number)
		{
			break;
		}

		str++;
		chr = *str;
	}

	return (sign * number);
}

/**
 * isDigit - Checks if a character is a valid digit
 */
int isDigit(char ch) {
	return (ch >= '0' && ch <= '9');
}

/**
 * expandArray - Increases the length of an array by deallocating the old array
 *               and allocating a larger array
 *
 * @ptr: A pointer to the array whose length is to be increased
 * @oldLength: The size (in bytes) of the array.
 * @newLength: The new size (in bytes) of the array.
 *
 * Return: on success, if both sizes are equal, a pointer to the original array,
 *         otherwise a pointer to the reallocated memory block.
 *         on failure, a null pointer
 */
void* expandArray(void* ptr, unsigned int oldLength, unsigned int newLength)
{
	char* newPtr, *copiedPtr;
	unsigned int i;

	if (newLength == oldLength)
		return (ptr);

	if (ptr == NULL)
		return (malloc(newLength));

	if (newLength == 0)
	{
		free(ptr);
		return (NULL);
	}

	newPtr = malloc(newLength);
	if (newPtr == NULL)
	{
		free(ptr);
		return (NULL);
	}

	copiedPtr = ptr;
	for (i = 0; (i < oldLength) && (i < newLength); i++)
		newPtr[i] = copiedPtr[i];

	free(ptr);
	return (newPtr);
}

