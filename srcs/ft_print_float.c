/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:47:47 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/19 14:15:47 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_float(t_base *base, va_list ap)
{
	long double	num;

	num = 0;
	if (base->precision == 0 || base->prec_is_neg)
		base->precision = 6;
	num = (base->modificator == 'f') ?
		va_arg(ap, long double) : va_arg(ap, double);
	base->is_negative = (num < 0) ? 1 : 0;
	base->is_zero = (num == 0) ? 1 : 0;
	ft_print_float(base, num);
}

char	*ft_put_width(char *print, t_base *base)
{
	size_t	len;
	size_t	neg_flag;

	if ((len = ft_strlen(print)) && base->flags[0])
		if (!ft_char_in_str(print, '.'))
			ft_strappend_xo_chr(&print, '.');
	if (!base->flags[2] && base->flags[1])
	{
		neg_flag = 0;
		if (len < base->width)
		{
			if (*print == '-' && ++len && (neg_flag = 1))
				*print = '0';
			else
				len += (ft_isascii(base->flags[3])
					|| ft_isascii(base->flags[4]));
			while (len++ < base->width)
				ft_strappend_ox("0", &print);
			if (neg_flag)
				ft_strappend_ox("-", &print);
		}
	}
	if (!base->flags[3] && base->flags[4] && ft_isdigit(*print))
		ft_strappend_ox(" ", &print);
	return (print);
}

void	ft_put_adds(char *print, t_base *base)
{
	size_t	len;

	len = ft_strlen(print) - (*print == '-');
	if (base->precision > (int)len)
		if (base->is_negative && ++len)
		{
			*print = '0';
			ft_strappend_ox("-", &print);
		}
	print = ft_put_width(print, base);
	if (base->flags[3] && ft_isdigit(*print))
		ft_strappend_ox("+", &print);
	len = ft_strlen(print);
	if (len < base->width)
	{
		if (base->flags[2])
			while (len++ < base->width)
				ft_strappend_xo(&print, " ");
		else
			while (len++ < base->width)
				ft_strappend_ox(" ", &print);
	}
	ft_putstr(print);
	base->len += ft_strlen(print);
	free(print);
}

void	ft_print_float(t_base *base, long double num)
{
	char	*print;

	if (num != num)
	{
		print = ft_strdup("nan");
		base->precision = -1;
		base->flags[0] = '\0';
		base->flags[1] = '\0';
	}
	else if (num == (1.0 / 0.0)
		|| num == (-1.0 / 0.0))
	{
		print = (num == (1.0 / 0.0)) ?
				ft_strdup("inf") : ft_strdup("-inf");
		base->precision = -1;
		base->flags[0] = '\0';
		base->flags[1] = '\0';
	}
	else if (!(print = ft_dtoa(num, base->precision < 0
		? 0 : base->precision, 10)))
		print = "";
	if (base->is_zero && !(1 / num > 0))
		ft_strappend_ox("-", &print);
	ft_put_adds(print, base);
}
