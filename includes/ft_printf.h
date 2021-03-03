/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 06:43:18 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/31 19:58:39 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define ALL_SYM	"cspdiuxX%-0.*123456789"
# define SPEC_TYPE	"cspdiuxX%"

# define H			1
# define HH			2
# define L			3
# define LL			4

# define POSITIVE	1
# define NEGATIVE	2

typedef struct	s_struct
{
	char		*format;
	int			nprinted;

	int			i;
	int			len;

	int			minus;
	int			zero;
	int			space;
	int			plus;
	int			hash;

	int			width;
	int			precisiontf;
	int			precision;
	int			length;
}				t_struct;

int				ft_printf(const char *format, ...);
int				ft_find_percent(const char *format, t_struct *f,
				va_list ap, int pos);
int				ft_parser(const char *format, t_struct *f, va_list ap, int pos);
int				signed_nbr_len(intmax_t n, int base);
int				unsigned_nbr_len(uintmax_t n, int base);
void			ft_zero_struct(t_struct *f);
void			ft_parse_flags(const char *format, t_struct *f);
void			ft_parse_width(const char *format, t_struct *f, va_list ap);
void			ft_parse_precision(const char *format, t_struct *f,
				va_list ap, int p);
void			ft_parse_modifiers(const char *format, t_struct *f, va_list ap);
void			ft_parse_type(va_list ap, t_struct *f, char c);
void			type_char(t_struct *f, va_list ap);
void			type_hex(t_struct *f, va_list ap, char x);
void			type_int(t_struct *f, va_list ap, int sign, intmax_t n);
void			type_un_int(t_struct *f, va_list ap);
void			type_percent(t_struct *f);
void			write_zero_space(int num, int f);
void			type_pointer(t_struct *f, va_list ap, int ox);
void			type_string(t_struct *f, va_list ap);
void			width_star(const char *format, t_struct *f, va_list ap);

#endif
