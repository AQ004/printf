#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - function that produces output according to a format.
 * @format: characters
 * @...: arguments
 *
 * Return: sum
 */

int _printf(const char *format, ...)
{
	specifier_t Specifiers[] = {
		{"%d", integer_f}, {"%i", integer_f}, {"%u", unsigned_f},
		{"%s", string_f}, {"%c", character_f}, {"%p", pointer_f},
		{"%x", hex_f}, {"%X", HEX_f}, {"%%", persand},
		{"%o", octal_f}, {"%b", binary_f}, {"%S", exclusive_str},
		{"%r", _rev}, {"%R", rot13}
	};
	int i = 0, j, sum = 0;
	va_list arguments;

	va_start(arguments, format);
	if ((!format || (format[0] == '%' && !format[1]))
			|| (format[0] == '%' && format[1] == ' ' && !format[2]))
		return (-1);
x:
	for (; format[i]; )
	{
		for (j = 0; j <= 13; j++)
			if (Specifiers[j].specifier[0] == format[i] &&
					Specifiers[j].specifier[1] == format[i + 1])
			{
				sum += Specifiers[j].function(arguments);
				i += 2;
				goto x;
			}
		_putchar(format[i]);
		sum++;
		i++;
	}
	va_end(arguments);
	return (sum);
}
/**
 * character_f - print char
 * @a: arguments stored in it
 *
 * Description: to print characters
 * Return: 1
 */
int character_f(va_list a)
{
	char c;

	c = va_arg(a, int);
	_putchar(c);
	return (1);
}

/**
 * integer_f - integer func
 * @a: arguments
 * Return: i
 */
int integer_f(va_list a)
{
	int i = 0, num1 = va_arg(a, int);
	int num, last_n = num1 % 10, digit, exp = 1;

	num1 /= 10;
	num = num1;
	if (last_n < 0)
	{
		_putchar('-');
		num = -num;
		num1 = -num1;
		last_n = -last_n;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = num1;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last_n + '0');
	return (i);
}
/**
 * string_f - prints string
 * @val: arguments
 *
 * Description: prints any string
 * Return: sum
 */
int string_f(va_list val)
{
	char *str;
	int i, sum;

	str = va_arg(val, char *);
	if (str == NULL)
	{
		str = "(null)";
		sum = _strlen(str);
		for (i = 0; i < sum; i++)
			_putchar(str[i]);
		return (sum);
	}
	else
	{
		sum = _strlen(str);
		for (i = 0; i < sum; i++)
			_putchar(str[i]);
		return (sum);
	}
}

