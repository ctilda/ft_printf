/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_un_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:39:13 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 19:07:30 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		rwidthandzero(t_struct *f, char c, int sign, char signc)
{
	if (f->width > 0 && c == '0')
	{
		if (f->space)
		{
			f->nprinted += write(1, " ", 1);
			f->space = 0;
		}
		if (sign != '\0')
			f->nprinted += write(1, &signc, 1);
		sign -= sign;
	}
	return (sign);
}

void	right_aligned_uint(t_struct *f, int intlen, char *s, int sign)
{
	char	signc;
	char	c;

	c = f->zero && !f->precisiontf ? '0' : ' ';
	sign = 0;
	signc = '\0';
	if (f->width > 0 && c == '0')
		sign = rwidthandzero(f, c, sign, signc);
	else if (f->width <= 0 && signc != '\0')
	{
		f->nprinted += write(1, &signc, 1);
		sign -= sign;
	}
	while (f->width-- > 0)
		f->nprinted += write(1, &c, 1);
	if (f->space != 0)
		f->nprinted += write(1, " ", 1);
	if (sign != 0 && signc != '\0')
		f->nprinted += write(1, &signc, 1);
	while (f->precision-- > 0)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, s, intlen);
}

void	left_aligned_uint(t_struct *f, int hexlenp, char *s, int sign)
{
	sign = 0;
	if (f->space)
		f->nprinted += write(1, " ", 1);
	if (sign == POSITIVE)
		f->nprinted += write(1, "+", 1);
	else if (sign == NEGATIVE)
		f->nprinted += write(1, "-", 1);
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, s, hexlenp);
	while (f->width > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

void	formating_uint(uintmax_t n, t_struct *f, int sign)
{
	char	*s;
	int		intlen;

	if (f->space && sign != 0)
		f->space = 0;
	s = ft_itoa_base(n, 10);
	intlen = unsigned_nbr_len(n, 10);
	if (n == 0)
		intlen = 1;
	if (f->precisiontf && f->precision == 0 && n == 0)
		intlen = 0;
	if (f->precisiontf && f->precision > intlen)
		f->precision = f->precision - intlen;
	else
		f->precision = 0;
	if (sign != 0)
		f->width = f->width - (f->precision + intlen + 1 + f->space);
	else
		f->width = f->width - (f->precision + intlen + f->space);
	if (f->minus == 0)
		right_aligned_uint(f, intlen, s, sign);
	if (f->minus == 1)
		left_aligned_uint(f, intlen, s, sign);
	free(s);
}

void	type_un_int(t_struct *f, va_list ap)
{
	uintmax_t	n;
	int			sign;

	sign = 0;
	n = 0;
	if (f->space)
		f->space = 0;
	if (f->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == HH)
		n = (unsigned char)va_arg(ap, int);
	else if (f->length == H)
		n = (unsigned short int)va_arg(ap, int);
	else if (f->length == LL)
		n = (unsigned long long int)va_arg(ap, long long int);
	else if (f->length == L)
		n = (unsigned long int)va_arg(ap, long int);
	if (f->plus)
		sign = POSITIVE;
	formating_uint(n, f, sign);
}
