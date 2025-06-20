/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sombru <sombru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:52:18 by sombru            #+#    #+#             */
/*   Updated: 2025/06/20 16:48:47 by sombru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// malloc, free, write,
// va_start, va_arg, va_copy, va_end

inline static void resolve_invalid_flags(t_format *f)
{
	if (f->zero && f->minus)
		f->zero = 0;
	if (f->minus && f->default_)
		f->default_ = 0;
	if (f->plus && f->space)
		f->space = 0;
}

inline static char *get_format_string(const char *input)
{
	int i;

	i = 0;
	while (!ft_strchr("cspdiuxX%", *input))
	{
		(input)++;
		i++;
	}
	return (ft_strndup(input - i, i + 1));
}

int expand(const char *input, va_list arg)
{
	t_format f;
	char *format_string;

	if (*input == '%')
		return (write(1, "%", 1));
	format_string = get_format_string(input);
	// printf("format string:%s\n", format_string);
	f.default_ = 1;
	f.dot = 0;
	f.field_witdh = 0;
	f.hash = 0;
	f.minus = 0;
	f.plus = 0;
	f.precision = 0;
	f.space = 0;
	f.zero = 0;
	f.specifier = 'n';
	parse_flags(format_string, &f);
	resolve_invalid_flags(&f);
	// parse_width(format_string, &f);
	// parse_precision(format_string, &f);
	parse_specifier(format_string, &f);
	// debug_format(&f);
	free(format_string);
	return (convert(&f, arg));
}

int ft_printf(const char *input, ...)
{
	int count;
	va_list arg;

	count = 0;
	// printf("input: %s", input);
	va_start(arg, input);
	while (*input)
	{
		if (*input == '%')
		{
			count += expand(++input, arg);
			while (!ft_strchr("cspdiuxX%", *input))
				input++;			
		}
		else
			count += write(STDOUT_FILENO, input, 1);
		input++;
	}
	va_end(arg);
	return count;
}

// int main()
// {
// 	char str[] = "aa";
// 	printf("my return: %d\n",ft_printf("|%.1s %.2s %.3s %.4s|\n", " - ", "", "4", (char*)NULL));

// 	printf("ori return: %d\n", printf("|%.1s %.2s %.3s %.4s|\n", " - ", "", "4", (char*)NULL));
// 	(void)str;
	
// 	return 0;
// }
