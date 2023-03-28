#include "main.h"

/**
 * handle_buffer - handles character identifier
 * @buffer: the print buffer
 * @c: character to handle
 * @index: index pointer for buffer fill position
 * Return: int
 */
int handle_buffer(char *buffer, char c, int *index)
{
	if (*index == BUFFER_SIZE)
	{
		print_buffer(buffer, *index);
		*index = 0;
	}
	buffer[*index] = c;
	(*index)++;
	return (*index);
}
