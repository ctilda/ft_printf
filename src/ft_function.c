/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 07:24:01 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 19:19:34 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_zero_struct(t_struct *f)
{
	f->len = 0;
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->hash = 0;
	f->width = 0;
	f->precisiontf = 0;
	f->precision = 0;
	f->length = 0;
}

int		signed_nbr_len(intmax_t n, int base)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

int		unsigned_nbr_len(uintmax_t n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

void	width_star(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width = -(f->width);
		}
		while (format[f->i] == '*')
			f->i++;
	}
}

void	write_zero_space(int num, int f)
{
	while (num-- > 0)
	{
		if (f == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}
