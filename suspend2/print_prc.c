#include "main.h"

/**
 * print_prc - handle percentage
 * @a: input char
 * @buffer: buffer pointer
 * @i: pointer location on buffer
 * Return: int
 */
int print_prc(va_list a __attribute__((unused)), char *buffer, int i)
{
	handle_buffer(buffer, '%', &i);

	return (1);
}
