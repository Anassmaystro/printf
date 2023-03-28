#include "main.h"

/**
 * print_char - writes char to output stream
 * @list: va_list
 * @buffer: char pointer
 * @buffer_counter: int buffer counter
 * Return: int
 */
int print_char(va_list list, char *buffer, int buffer_counter)
{
	char s = va_arg(list, int);

	handle_buffer(buffer, s, &buffer_counter);

	return (1);
}
