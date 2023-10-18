#include "main.h"
/**
 * persand - function that prints %
 * Return: 1
 */
int persand()
{
	_putchar('%');
	return (1);
}

/**
 * _strlen - function that returns the length of a string.
 * @s: pointer to char
 *
 * Return: length of the array
 */
int _strlen(char *s)
{
	int counter;

	for (counter = 0; s[counter] != '\0'; counter++)
		;
	return (counter);
}

