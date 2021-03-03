/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:41:51 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 20:34:33 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		hex_count(unsigned long long n)
{
	int		i;

	i = 0;
	while (n / 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int		right_aligned_ptr(int widthp, int precisionp, int hexlenp, char *s)
{
	int		i;

	i = 0;
	while (widthp > 0)
	{
		i += write(1, " ", 1);
		widthp--;
	}
	i += write(1, "0x", 2);
	while (precisionp > 0)
	{
		i += write(1, "0", 1);
		precisionp--;
	}
	i += write(1, s, hexlenp);
	return (i);
}

int		left_aligned_ptr(int widthp, int precisionp, int hexlenp, char *s)
{
	int i;

	i = 0;
	i += write(1, "0x", 2);
	while (precisionp > 0)
	{
		i += write(1, "0", 1);
		precisionp--;
	}
	i += write(1, s, hexlenp);
	while (widthp > 0)
	{
		i += write(1, " ", 1);
		widthp--;
	}
	return (i);
}

void	type_pointer(t_struct *f, va_list ap, int oxheading)
{
	int					hexlenp;
	char				*s;
	int					precisionp;
	int					widthp;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(ap, void *);
	hexlenp = hex_count(pointer) + 1;
	s = ft_itoa_base(pointer, 16);
	precisionp = f->precision - hexlenp;
	widthp = f->width - hexlenp - oxheading;
	if (f->precisiontf && f->precision == 0 && pointer == 0)
		widthp++;
	if (f->precisiontf && f->precision == 0)
		hexlenp = 0;
	if (f->minus)
		f->nprinted += left_aligned_ptr(widthp, precisionp, hexlenp, s);
	else
		f->nprinted += right_aligned_ptr(widthp, precisionp, hexlenp, s);
	free(s);
}
