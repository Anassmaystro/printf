#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct parser_f {
	char *arg;
	int (*function)(va_list, char *, int);
} parser;

int _printf(const char *format, ...);
int handle_buffer(char *buffer, char c, int *index);
int print_buffer(char *buffer, int index);
int (*get_parser(const char *s, int index))(va_list, char *, int);
int parse_print_func(const char *s, int index);
int print_char(va_list list, char *buffer, int buffer_counter);
int print_string(va_list args, char *buffer, int buffer_counter);
int print_prc(va_list a __attribute__((unused)), char *buffer, int i);
#endif

