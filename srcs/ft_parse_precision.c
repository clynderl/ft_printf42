/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:19:58 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/14 15:23:26 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_precision(t_base *base, const char *fmt, va_list ap)
{
	int pr;

	base->dot = 1;
	if (fmt[base->i += 1] == '*')
	{
		pr = va_arg(ap, int);
		if (pr < 0)
		{
			base->precision = pr * -1;
			base->prec_is_neg = 1;
		}
		else
			base->precision = pr;
		base->i++;
		return ;
	}
	if (fmt[base->i] == '-' || !ft_isdigit(fmt[base->i]))
	{
		base->precision = -1;
		return ;
	}
	while (fmt[base->i] == '0' && ft_isdigit(fmt[base->i + 1]))
		base->i++;
	base->precision = ft_atoi(fmt + base->i);
	base->i += ft_num_len(base->precision);
}
