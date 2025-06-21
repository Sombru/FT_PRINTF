/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sombru <sombru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:59:14 by sombru            #+#    #+#             */
/*   Updated: 2025/06/21 15:00:15 by sombru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*get_string(const char *arg)
{
	const char	*str;

	if (arg)
		str = arg;
	else
		str = "(null)";
	return (str);
}

int	print_string(t_format *f, const char *arg)
{
	int			count;
	int			len;
	const char	*str;

	str = get_string(arg);
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
