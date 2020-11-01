/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:26:31 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/17 17:08:01 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct	s_base
{
	char		flags[5];
	size_t		width;
	int			precision;
	char		modificator;
	char		conversion;
	size_t		i;
	size_t		len;
	int			dot;
	size_t		prec_is_neg;
	size_t		is_negative;
	size_t		is_zero;
}				t_base;

int				ft_printf(const char *fmt, ...);
int				ft_parse(t_base *base, const char *fmt, va_list ap);
void			ft_parse_flag(t_base *base, const char *fmt);
void			ft_parse_width(t_base *base, const char *fmt);
void			ft_parse_width_s(t_base *base, int w);
void			ft_parse_precision(t_base *base, const char *fmt, va_list ap);
void			ft_parse_modificator(t_base *base, const char *fmt);
void			ft_process(t_base *base, va_list ap);
void			ft_print_bin(t_base *base, unsigned long long arg);
void			ft_print_unsigned(t_base *base, unsigned long long arg);
void			ft_print_signed_neg(t_base *base, long long int arg);
void			ft_print_signed(t_base *base, long long int arg);
int				ft_num_len(long long int n);
void			ft_putulnbr(unsigned long long n);
int				ft_num_len_base(long long int nb, char *base);
void			ft_print_num_base(long long int nb, char *base);
void			ft_putsharp(t_base *base);
int				ft_char_in_str(const char *s, int c);
void			ft_print_percent(t_base *base);
void			ft_print_char(t_base *base, char arg);
void			ft_print_string(t_base *base, char *arg);
void			ft_print_ptr(t_base *base, uintptr_t arg);
void			ft_convert_float(t_base *base, va_list ap);
void			ft_print_float(t_base *base, long double num);

#endif
