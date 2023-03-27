#include <stdio.h>
#include "main.h"

#define BUFFER_SIZE 100

/**
 * _printf - Custom printf function
 * @format: char pointer array
 * Return: will think about it
 */
int _printf(const char *format, ...)
{
	va_list list;
	char buffer[BUFFER_SIZE];
	int counter;
	int buffer_counter;
	char *s;
	int printed_counter;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	counter = 0;
	buffer_counter = 0;
	printed_counter = 0;
	while (format && format[counter] != '\0')
	{
		if (format[counter] == '%')
		{
			counter++;
			switch (format[counter])
			{
				case 'c':
					{
						buffer[buffer_counter++] = (char)va_arg(list, int);
						printed_counter++;
						break;
					}
				case 's':
					{
						s = va_arg(list, char *);
						while (*s != '\0')
						{
							buffer[buffer_counter++] = *s;
							s++;
						}
						printed_counter++;
						break;
					}
				case '%':
					{
						buffer[buffer_counter++] = '%';
						printed_counter++;
						break;
					}
				case 'n':
					{
						buffer[buffer_counter++] = '\n';
						printed_counter++;
						break;
					}	
			}
		}
		else
		{
			buffer[buffer_counter++] = (char)format[counter];
			printed_counter++;
		}
		counter++;
	}
	if (buffer_counter > 0)
	{
		write(1, &buffer[0], buffer_counter);
	}
	va_end(list);
	return (printed_counter);
}
