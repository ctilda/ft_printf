/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_modifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 07:30:08 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 19:14:35 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_flags(const char *format, t_struct *f)
{
	while (ft_strchr("-0", format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		if (format[f->i] == '0')
			f->zero = 1;
		f->i++;
	}
}

void	ft_parse_width(const char *format, t_struct *f, va_list ap)
{
	width_star(format, f, ap);
	if (format[f->i] >= '0' && format[f->i] <= '9')
	{
		f->width = ft_atoi(&format[f->i]);
		while (format[f->i] >= '0' && format[f->i] <= '9')
		{
			f->i++;
			if (format[f->i] == '*')
			{
				if (f->width < 0)
				{
					f->minus = 1;
					f->width = -(f->width);
				}
				while (format[f->i] == '*')
					f->i++;
			}
		}
	}
}

void	ft_parse_precision(const char *format, t_struct *f, va_list ap, int p)
{
	int		i;

	i = f->i;
	if (format[i] == '.')
	{
		i++;
		f->precisiontf = 1;
		if (format[i] >= '0' && format[i] <= '9')
		{
			f->precision = ft_atoi(&format[i]);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
		}
		else if (format[i] == '*')
		{
			p = va_arg(ap, int);
			if (p >= 0)
				f->precision = p;
			else if (p < 0)
				f->precisiontf = 0;
			while (format[i] == '*')
				i++;
		}
	}
	f->i = i;
}

void	ft_parse_modifiers(const char *format, t_struct *f, va_list ap)
{
	ft_parse_flags(format, f);
	ft_parse_width(format, f, ap);
	ft_parse_precision(format, f, ap, 0);
}
