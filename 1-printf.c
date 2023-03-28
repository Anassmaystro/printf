#include "main.h"

void handleCharacter(int *buffer_counter, va_list list,
		int *printed_counter, char *buffer);
void handleString(int *buffer_counter, va_list list,
			int *printed_counter, char *buffer);

/**
 * _printf - Custom printf function
 * @format: char pointer array
 * Return: will think about it
 */
int _printf(const char *format, ...)
{
	va_list list;
	char *buffer;
	int counter = 0, buffer_counter = 0, printed_counter = 0;
	int (*parser)(va_list, char *, int);


	va_start(list, format);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!format || !buffer || (format[counter] == '%' && !format[counter + 1]))
		return (-1);
	if (!format[counter])
		return (0);

	for (counter = 0; format && format[counter]; counter++)
	{
		if (format[counter] == '%')
		{
			if (format[counter + 1] == '\0')
			{
				print_buffer(buffer, buffer_counter);
				free(buffer);
				va_end(list);
				return (-1);
			}
			else
			{
				parser = get_parser(format, counter + 1);
				if (parser == NULL)
				{
					if (format[counter + 1] == ' ' && !format[counter + 2])
					{
						return (-1);
					handle_buffer(buffer, format[counter], &buffer_counter);
					printed_counter++;
					counter--;
					}
				}
				else
				{
					printed_counter += parser(list, buffer, buffer_counter);
					counter += parse_print_func(format, counter + 1);
				}
			} counter++;
		}
		else
		{
			handle_buffer(buffer, format[counter], &buffer_counter);
			printed_counter++;
		}
		for (buffer_counter = printed_counter; buffer_counter > BUFFER_SIZE;
					buffer_counter -= BUFFER_SIZE)
			;
	}
		print_buffer(buffer, buffer_counter);
		free(buffer);
		va_end(list);
		return (printed_counter);
}
