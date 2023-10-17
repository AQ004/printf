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

#endif

