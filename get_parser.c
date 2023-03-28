#include "main.h"

/**
 * get_parser - function pointer
 * @s: char pointer
 * @index: int
 * Return: int
 */
int (*get_parser(const char *s, int index))(va_list, char *, int)
{
	parser parsers[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_prc},
		{" %", print_prc},
	};

	int i = 0, j = 0, first_index;

	first_index = index;

	while (parsers[i].arg)
	{
		if (s[index] == parsers[i].arg[j])
		{
			if (parsers[i].arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (parsers[i].function);
}
