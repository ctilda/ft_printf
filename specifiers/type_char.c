/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:24:07 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 20:33:45 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	type_char(t_struct *f, va_list ap)
{
	unsigned char	c;
	int				num;

	num = 0;
	c = (unsigned char)va_arg(ap, int);
	if (f->width && f->minus == 0)
	{
		num = f->width - 1;
		if (f->zero != 0)
			write_zero_space(num, 0);
		else if (f->zero == 0)
			write_zero_space(num, 1);
		write(1, &c, 1);
		f->nprinted += num;
	}
	else if (f->width && f->minus == 1)
	{
		num = f->width - 1;
		write(1, &c, 1);
		write_zero_space(num, 1);
		f->nprinted += num;
	}
	else
		write(1, &c, 1);
	f->nprinted++;
}
