/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:51:01 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 19:28:09 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t val, uintmax_t base)
{
	unsigned long long	n;
	char				*s;
	int					i;

	i = 1;
	n = val;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	while (i-- > 0)
	{
		s[i] = (val % base < 10) ? val % base + '0' : val % base + 'a' - 10;
		val /= base;
	}
	return (s);
}

char	*ft_itoa_base_upper(intmax_t val, intmax_t base)
{
	long long	n;
	char		*s;
	int			sign;
	int			i;

	n = (val < 0) ? -val : val;
	sign = (val < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (val < 0) ? -val : val;
	while (i-- + sign)
	{
		s[i] = (val % base < 10) ? val % base + '0' : val % base + 'A' - 10;
		val /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
