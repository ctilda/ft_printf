/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 06:35:44 by ctilda            #+#    #+#             */
/*   Updated: 2021/01/03 16:15:29 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*f;
	int			len;
	int			num;

	len = ft_strlen(format);
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	ft_bzero(f, sizeof(t_struct));
	f->format = (char *)format;
	va_start(ap, format);
	if (!format[0] || (len == 1 && format[0] == '%'))
	{
		free(f);
		return (0);
	}
	else
		num = ft_find_percent(format, f, ap, 0);
	va_end(ap);
	free(f);
	return (num);
}
