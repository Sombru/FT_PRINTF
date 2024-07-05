/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura < pkostura@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:12:11 by pkostura          #+#    #+#             */
/*   Updated: 2023/11/23 17:43:37 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

// int	ft_printf(const char *format, ...);
// int	printf_format(char specifier, va_list ap);
// int	print_char(int c);
// int	print_str(char *str);
// int	print_digit(long n, int base);
// int	print_digit_cap(long n, int base);
// int	print_pointer(long n, int base);
// int	print_digit_p(unsigned long n, unsigned int base);

// int main(void)
// {
// 	int 	value = 0;
// 	int		count = 5 + 6;
// 	char	*str = "John";
// 	char	*vod = "sussy baka simulator";
// 	char 	*null_str = NULL;

// 	value = ft_printf("Hello geys %s Hello geys %s\n", str, str);
// 	value = printf("Hello geys %s Hello geys %s\n", str, str);
// 	ft_printf("value of prinf: %d\n", value);
// 	printf("value of printf: %d\n", value);
// 	//digits
// 	ft_printf("5 + 6 = %i\n", count);
// 	printf("5 + 6 = %i\n", count);
// 	//insigned
// 	ft_printf("unsigned int -> %u\n", -46);
// 	printf("unsigned int  -> %u\n", -46);
// 	//hexidecimal
// 	ft_printf("hexidecimal of 11 -> %x\n", count);
// 	printf("hexidecimal of 11 -> %x\n", count);
// 	//print hex capital
// 	ft_printf("hexidecimal of 12(CAP) -> %X\n", -12);
// 	printf("hexidecimal of 12(CAP) -> %X\n", -12);
// 	//print hex capital
// 	ft_printf("print where poiner is stored -> %p\n", vod);
// 	printf("print where poiner is stored -> %p\n", vod);
// 	//print%
// 	ft_printf("percent sign -> %%\n");
// 	printf("percent sign -> %%\n");
// 	//null string
// 	ft_printf("null str: %s\n", null_str);
// 	printf("null str: %s\n", null_str);
// 	null pointer
// 	ft_printf("null pointer: %p\n", null_str);
// 	printf("null pointer: %p\n", null_str);
// 	//idk
// 	ft_printf("null -1: %p\n", (void *)-2);
// 	printf("null -1: %p\n", (void *)-2);
// 	return (0);
// }

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		ap;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += printf_format((*++format), ap);
			format++;
		}
		else
			count += write(1, format++, 1);
	}
	va_end(ap);
	return (count);
}

int	printf_format(char specifier, va_list ap)
{
	int		count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg(ap, int), 10);
	else if (specifier == 'u')
		count += print_digit((long)va_arg(ap, unsigned int), 10);
	else if (specifier == 'p')
		count += print_pointer((unsigned long)va_arg(ap, void *), 16);
	else if (specifier == 'x')
		count += print_digit((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count += print_digit_cap((long)va_arg(ap, unsigned int), 16);
	else if (specifier == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

// int	print_char(int c)
// {
// 	return (write(1, &c, 1));
// }

// int	print_str(char *str)
// {
// 	int		count;

// 	if (str == NULL)
// 	{
// 		write(1, "(null)", 6);
// 		return (0);
// 	}
// 	count = 0;
// 	while (*str)
// 	{
// 		print_char((int)*str);
// 		str++;
// 	}
// 	return (count);
// }

// int print_pointer(long n, int base)
// {
// 	int 		 count;
// 	unsigned long i;
// 	if (n == 0)
// 	{
// 		write(1, "(nil)", 5);
// 		return(5);
// 	}
// 	i = n;
// 	count += write(1, "0x", 2);
// 	count += print_digit_p(i, 16);
// 	return(count);
// }

// int	print_digit_p(unsigned long n, int base)
// {
// 	int		count;
// 	char	*symbols;

// 	symbols = "0123456789abcdef";
// 	count = 0;
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		return (print_digit_p(-n, base));
// 	}
// 	else if (n < base)
// 	{
// 		return (print_char(symbols[n]));
// 	}
// 	else
// 	{
// 		count = print_digit_p(n / base, base);
// 		return (count + print_digit_p(n % base, base));
// 	}
// }

// int	print_digit(long n, int base)
// {
// 	int		count;
// 	char	*symbols;

// 	symbols = "0123456789abcdef";
// 	count = 0;
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		return (print_digit(-n, base));
// 	}
// 	else if (n < base)
// 	{
// 		return (print_char(symbols[n]));
// 	}
// 	else
// 	{
// 		count = print_digit(n / base, base);
// 		return (count + print_digit(n % base, base));
// 	}
// }

// int	print_digit_cap(long n, int base)
// {
// 	int		count;
// 	char	*symbols;

// 	symbols = "0123456789ABCDEF";
// 	count = 0;
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		count++;
// 		return (print_digit_cap(-n, base));
// 	}
// 	else if (n < base)
// 	{
// 		return (print_char(symbols[n]));
// 	}
// 	else
// 	{
// 		count = print_digit_cap(n / base, base);
// 		return (count + print_digit_cap(n % base, base));
// 	}
// }
