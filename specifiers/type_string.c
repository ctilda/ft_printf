/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:35:47 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 20:32:48 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	right_aligned_str(t_struct *f, char c, char *s, int i)
{
	if (f->minus != 0)
	{
		c = ' ';
		if (f->precisiontf && i > f->precision)
			i = f->precision;
		f->len += write(1, s, i);
		f->nprinted = f->nprinted + i;
		while (f->width > i)
		{
			f->len += write(1, &c, 1);
			f->nprinted++;
			f->width--;
		}
	}
}

void	left_aligned_str(t_struct *f, char c, char *s, int i)
{
	if (f->minus == 0)
	{
		if (f->precisiontf && i > f->precision)
			i = f->precision;
		if (f->width > i)
		{
			while ((f->width - i) > 0)
			{
				f->len += write(1, &c, 1);
				f->nprinted++;
				f->width--;
			}
		}
		f->len += write(1, s, i);
		f->nprinted = f->nprinted + i;
	}
}

void	type_string(t_struct *f, va_list ap)
{
	char	*s;
	int		i;
	char	c;

	if (f->zero == 1)
		c = '0';
	else
		c = ' ';
	s = (char *)va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	i = ft_strlen(s);
	if (f->minus == 1)
		right_aligned_str(f, c, s, i);
	else if (f->minus == 0)
		left_aligned_str(f, c, s, i);
}
