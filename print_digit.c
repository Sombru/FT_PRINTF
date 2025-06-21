/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sombru <sombru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:24:11 by sombru            #+#    #+#             */
/*   Updated: 2025/06/21 15:05:59 by sombru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa_printf(unsigned int n, int *out_nbr_len)
{
	char	*str;
	int		len;

	if (!n)
	{
		*out_nbr_len = 1;
		return (ft_strdup("0"));
	}
	len = ft_nbrlen(n);
	*out_nbr_len = len;
	str = malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	while (len-- && n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	resolve_digit_sign(t_format *f, int *is_negative, int *len)
{
	int	count;

	count = 0;
	if (f->zero || *is_negative || f->plus)
	{
		if (f->plus && *is_negative == 0)
		{
			count += write(1, "+", 1);
			(*len)++;
		}
		if (*is_negative)
		{
			count += write(1, "-", 1);
			(*len)++;
		}
	}
	return (count);
}

// Enough for -2147483648\0
int	print_digit(t_format *f, int arg)
{
	char	*result;
	int		count;
	int		len;
	int		is_negative;

	count = 0;
	is_negative = 0;
	if (arg < 0)
	{
		is_negative = 1;
		arg = -arg;
		arg = (unsigned int)arg;
	}
	result = ft_itoa_printf(arg, &len);
	count += resolve_digit_sign(f, &is_negative, &len);
	if (is_negative && f->dot)
		len--;
	if (f->default_ && f->field_witdh)
		count += apply_format(f, len);
	if (!is_negative && f->space && !f->field_witdh)
		count += write(1, " ", 1);
	count += write(1, result, ft_strlen(result));
	if (f->minus && f->field_witdh)
		count += apply_format(f, len);
	return (free(result), count);
}

// int main()
// {
// 	print_digit(NULL, 45);
// }