#include <stdio.h>
#include "main.h"

#define BUFFER_SIZE 1000

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
	char buffer[BUFFER_SIZE];
	int counter, buffer_counter, printed_counter;

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
					handleCharacter(&buffer_counter, list, &printed_counter, buffer);
					break;
				case 's':
					handleString(&buffer_counter, list, &printed_counter, buffer);
					break;
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
	return (printed_counter);
}
/**
 * handleCharacter - handles strings, a utility of printf
 * @buffer_counter: buffer pointer
 * @list: va_list
 * @printed_counter: int pointer
 * @buffer: char pointer
 * Return: void
 */
void handleCharacter(int *buffer_counter, va_list list,
			int *printed_counter, char *buffer)
{
	char c = (char)va_arg(list, int);

	buffer[(*buffer_counter)++] = c;
	(*printed_counter)++;
}

/**
 * handleString - handles strings, a utility of printf
 * @buffer_counter: buffer pointer
 * @list: va_list
 * @printed_counter: int pointer
 * @buffer: char pointer
 * Return: void
 */
void handleString(int *buffer_counter, va_list list,
			int *printed_counter, char *buffer)
{
	char *s = va_arg(list, char *);

	while (s != NULL && *s != '\0')
	{
		buffer[(*buffer_counter)++] = *s;
		s++;
		(*printed_counter)++;
	}
}
