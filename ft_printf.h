#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct s_format
{
	int hash; // Used with x or X specifiers the value is preceded with 0x or 0X respectively for values different than zero.
	int minus; // Left justify the result within the field. By default it is right justified.
	int plus; // Always print the sign (+ or -) for numeric values.
	int dot; // Introduces the precision specifier (e.g., %.2f for two decimal places).
	int space; // Print a space before positive numbers (if + is not used).
	int zero; // Leading zeros are used to pad the numbers instead of space.
	int default_; // Flag for default right justified width
	int field_witdh; // Width for '-0 ' & default_ flags
	int precision; // Precision for '.' flag (%8d) 
	char specifier; // cspdiuxX%
}	t_format;

int convert(t_format *f, va_list arg);
int expand(const char *, va_list arg);
void parse_flags(char *, t_format *f);
int parse_width(char **, t_format *f);
void parse_specifier(const char *, t_format *f);
void parse_precision(const char *, t_format *f);

void debug_format(const t_format *f);

int apply_format(t_format *f, int);

int print_char(t_format *f, const int );
int print_string(t_format *f, const char *);
int print_pointer(t_format *f, void *);
int print_digit(t_format *f, int);
int print_unsigned(t_format *f, unsigned int);
int print_hex(t_format *f, unsigned int, int upper);

int ft_printf(const char *, ...);

#endif