#include "main.h"

/**
 * print_buffer - writes the buffer to output stream
 * @buffer: pointer to buffer (char pointer)
 * @index: buffer fill size
 * Return: int
 */
int print_buffer(char *buffer, int index)
{
	return (write(1, buffer, index));
}
