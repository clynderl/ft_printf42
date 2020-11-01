/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzoltan <gzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:07:43 by gzoltan           #+#    #+#             */
/*   Updated: 2020/08/14 18:07:48 by gzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_base(t_base *base, const char *fmt, va_list ap)
{
	while (fmt[base->i] == '-' || fmt[base->i] == '+' ||
			fmt[base->i] == ' ' || fmt[base->i] == '#' ||
			fmt[base->i] == '0')
		ft_parse_flag(base, fmt);
	if (ft_isdigit(fmt[base->i]) && fmt[base->i] != '0')
		ft_parse_width(base, fmt);
	if (fmt[base->i] == '*' || (fmt[base->i] == '-'
		&& fmt[base->i += 1] == '*'))
		ft_parse_width_s(base, va_arg(ap, int));
	if (fmt[base->i] == '.')
		ft_parse_precision(base, fmt, ap);
	if (fmt[base->i] == 'h' || fmt[base->i] == 'l' || fmt[base->i] == 'L')
		ft_parse_modificator(base, fmt);
}

int			ft_parse(t_base *base, const char *fmt, va_list ap)
{
	while ((fmt[base->i] == '-' || fmt[base->i] == '+' ||
				fmt[base->i] == '*' ||
				fmt[base->i] == ' ' || fmt[base->i] == '#' ||
				fmt[base->i] == '0' || fmt[base->i] == '.' ||
				fmt[base->i] == 'h' || fmt[base->i] == 'l' ||
				fmt[base->i] == 'L' || ft_isdigit(fmt[base->i])) &&
				fmt[base->i])
		ft_parse_base(base, fmt, ap);
	if (base->precision == 0 && base->dot == 1)
		base->precision = -1;
	if (ft_char_in_str("diouxXscpbf%", fmt[base->i]))
		base->conversion = fmt[base->i++];
	return (1);
}
