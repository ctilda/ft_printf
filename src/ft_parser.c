/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 07:01:54 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 18:48:44 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_parser(const char *format, t_struct *f, va_list ap, int pos)
{
	f->i = pos;
	if (!ft_strchr(SPEC_TYPE, format[pos]))
		ft_parse_modifiers(format, f, ap);
	else if (ft_strchr(SPEC_TYPE, format[pos]))
	{
		ft_parse_type(ap, f, format[pos]);
		ft_zero_struct(f);
	}
	return (f->i - 1);
}

int		ft_find_percent(const char *format, t_struct *f, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] && format[pos] != '%')
			f->nprinted += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!ft_strchr(ALL_SYM, format[pos + 1]))
				break ;
			while (ft_strchr(ALL_SYM, format[pos + 1]))
			{
				pos++;
				if (ft_strchr(SPEC_TYPE, format[pos]))
				{
					pos = ft_parser(format, f, ap, pos) + 2;
					break ;
				}
				else
					pos = ft_parser(format, f, ap, pos);
			}
			continue;
		}
		pos++;
	}
	return (f->nprinted);
}
