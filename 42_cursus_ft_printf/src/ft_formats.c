/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura < pkostura@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:54:25 by pkostura          #+#    #+#             */
/*   Updated: 2023/11/23 18:01:54 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_str(char *str)
{
	int		count;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	while (*str)
	{
		print_char((int)*str);
		str++;
		count++;
	}
	return (count);
}

int	print_pointer(long n, int base)
{
	int				count;
	unsigned long	i;

	count = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = n;
	base = 16;
	count += write(1, "0x", 2);
	count += print_digit_p(i, base);
	return (count);
}

int	print_digit_p(unsigned long n, unsigned int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (1 + print_digit_p(-n, base));
	}
	if (n < base)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_digit_p(n / base, base);
		return (count + print_digit_p(n % base, base));
	}
}

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (1 + print_digit(-n, base));
	}
	else if (n < base)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

// this code recursively breaks down the number 
// into its base representation and prints the digits accordingly,
// using a string of symbols to map digits to their character
// representations in the given base. The print_char function 
// handles the actual writing of characters to the standard output.

// For numbers greater than or equal to the base, it recursively 
// calls print_digit with n / base to handle the quotient part and 
// n % base to handle the remainder.
// count = print_digit(n / base, base);
// It sums the counts obtained from the quotient and remainder and 
// returns the total count of characters printed.

int	print_digit_cap(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (1 + print_digit_cap(-n, base));
	}
	else if (n < base)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_digit_cap(n / base, base);
		return (count + print_digit_cap(n % base, base));
	}
}
