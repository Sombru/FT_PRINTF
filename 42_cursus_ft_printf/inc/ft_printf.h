/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura < pkostura@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:50:10 by pkostura          #+#    #+#             */
/*   Updated: 2023/11/23 17:17:07 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	printf_format(char specifier, va_list ap);
int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base);
int	print_digit_cap(long n, int base);
int	print_pointer(long n, int base);
int	print_digit_p(unsigned long n, unsigned int base);

#endif