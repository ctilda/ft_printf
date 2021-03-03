/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:29:48 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 20:36:33 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	type_percent(t_struct *f)
{
	int		num;

	if (f->width != 0 && f->minus == 0)
	{
		num = f->width - 1;
		if (f->zero != 0)
			write_zero_space(num, 0);
		else
			write_zero_space(num, 1);
		write(1, "%", 1);
		f->nprinted = f->nprinted + num + 1;
	}
	else if (f->width && f->minus == 1)
	{
		num = f->width - 1;
		write(1, "%", 1);
		write_zero_space(num, 1);
		f->nprinted = f->nprinted + num + 1;
	}
	else
	{
		write(1, "%", 1);
		f->nprinted++;
	}
}
