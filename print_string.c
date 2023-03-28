#include "main.h"

/**
 * print_string - handle strings
 * @args: va_list
 * @buffer: character pointer
 * @buffer_counter: counter
 * Return: int
 */
int print_string(va_list args, char *buffer, int buffer_counter)
{
	char *str;
	int i;
	char nill[] = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			buffer_counter = handle_buffer(buffer, nill[i], &buffer_counter);
		return (6);
	}
	for (i = 0; str[i]; i++)
		buffer_counter = handle_buffer(buffer, str[i], &buffer_counter);
	return (i);
}
