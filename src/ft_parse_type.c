/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:16:51 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 18:53:37 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_type(va_list ap, t_struct *f, char c)
{
	if (c == 'c')
		type_char(f, ap);
	else if (c == 's')
		type_string(f, ap);
	else if (c == 'p')
		type_pointer(f, ap, 2);
	else if (c == 'd' || c == 'i')
		type_int(f, ap, 0, 0);
	else if (c == 'u')
		type_un_int(f, ap);
	else if (c == 'x' || c == 'X')
		type_hex(f, ap, c);
	else if (c == '%')
		type_percent(f);
}
