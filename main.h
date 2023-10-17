#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * specifiers - specifiers of the printf function
 * @specifier: pointer to char
 * @function: pointer to function
 */

typedef struct specifiers
{
	char *specifier;
	int (*function) ();
} specifier_t;

int _printf(const char *format, ...);
int pointer_f(va_list val);
int exclusive_str(va_list val);
int HEX_f(va_list val);
int hex_f(va_list val);
int octal_f(va_list val);
int unsigned_f(va_list args);
int binary_f(va_list val);
int _rev(va_list args);
int rot13(va_list args);
int integer_f(va_list args);
int _rev(char *s);
int persand(void);
int character_f(va_list val);
int string_f(va_list val);

#endif

