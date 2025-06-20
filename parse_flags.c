/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sombru <sombru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:23:42 by sombru            #+#    #+#             */
/*   Updated: 2025/06/20 13:40:42 by sombru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//  %[argument$][flags][width][.precision][length modifier]conversion
// '#+- 0'
void parse_flags(char *format_string, t_format *f)
{

	while (format_string && *format_string)
	{
		if (*format_string == '#')
			f->hash = 1;
		else if (*format_string == '+')
			f->plus = 1;
		else if (*format_string == ' ')
			f->space = 1;
		else if (*format_string == '-')
			f->minus = parse_width(&format_string, f);
		else if (*format_string == '0')
			f->zero = parse_width(&format_string, f);
		else if (*format_string == '.')
			f->dot = parse_width(&format_string, f);
		else if (*format_string != '0' && ft_isdigit(*format_string))
			f->default_ = parse_width(&format_string, f);
		format_string++;
	}
}

int parse_width(char **format_string, t_format *f)
{
	if (ft_isdigit((**format_string)))
		f->field_witdh = ft_atoi(*format_string);
	else
	{
		(*format_string)++;
		f->field_witdh = ft_atoi(*format_string);
	}
	while (ft_isdigit((**format_string)))
	{
		(*format_string)++;
	}
	return (1);
	// printf("width:%d\n", f->field_witdh);
}

// void parse_precision(const char *format_string, t_format *f)
// {
// 	format_string = ft_strchr(format_string, '.');
// 	if (!format_string)
// 		return ;
// 	f->dot = 1;
// 	format_string++;
// 	f->precision = ft_atoi(format_string);
// }

void parse_specifier(const char *format_string, t_format *f)
{
	while (*format_string != 0)
	{
		format_string++;
	}
	format_string--;
	f->specifier = *format_string;
}