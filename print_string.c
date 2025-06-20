/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sombru <sombru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:59:14 by sombru            #+#    #+#             */
/*   Updated: 2025/06/20 16:48:36 by sombru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_string(t_format *f, const char *arg)
{
	int count;
	int len;
	const char *str; 

	if (arg)
		str = arg;
	else
		str = "(null)";
	count = 0;
	len = ft_strlen(str);
	if (f->default_ && f->field_witdh && !f->dot)
		count += apply_format(f, len);
	if (f->dot)
	{
		if (!arg)
			return (0);
		if (len < f->field_witdh)
			count += write(1, str, len);
		else
			count += write(1, str, f->field_witdh);
	}
	else if (str)
		count += write(1, str, ft_strlen(str));
	if (f->minus && f->field_witdh && !f->dot)
		count += apply_format(f, len);
	return (count);
}