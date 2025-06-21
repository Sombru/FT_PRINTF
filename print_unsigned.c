/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sombru <sombru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:00:00 by sombru            #+#    #+#             */
/*   Updated: 2025/06/21 15:01:48 by sombru           ###   ########.fr       */
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

char	*ft_uitoa_printf(unsigned int n, int *out_nbr_len)
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
	while (len-- && n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

// Enough for -2147483648\0
int	print_unsigned(t_format *f, unsigned int arg)
{
	char	*result;
	int		count;
	int		len;

	count = 0;
	result = ft_uitoa_printf(arg, &len);
	if (f->default_ && f->field_witdh)
		count += apply_format(f, len);
	count += write(1, result, len);
	if (f->minus && f->field_witdh)
		count += apply_format(f, len);
	free(result);
	return (count);
}
