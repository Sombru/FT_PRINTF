/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sombru <sombru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:03:34 by sombru            #+#    #+#             */
/*   Updated: 2025/06/21 15:04:18 by sombru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(t_format *f, unsigned int arg, int upper)
{
	char	*hex;
	int		count;
	int		len;

	count = 0;
	hex = ft_xtoa(arg, upper);
	len = (int)ft_strlen(hex);
	if (f->hash && arg)
	{
		if (upper)
			count += write(1, "0X", 2);
		else
			count += write(1, "0x", 2);
		len += 2;
	}
	if (f->default_ && f->field_witdh)
		count += apply_format(f, len);
	count += write(1, hex, ft_strlen(hex));
	if (f->minus && f->field_witdh)
		count += apply_format(f, len);
	free(hex);
	return (count);
}
