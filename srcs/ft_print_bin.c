/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:05:53 by gzoltan           #+#    #+#             */
/*   Updated: 2020/08/17 17:41:48 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_width(t_base *base, int less, int bin_len)
{
	int	i;
	int	width_len;
	int	precision_len;

	i = 0;
	if (base->precision > 0 && base->precision < bin_len
		&& base->precision > (int)base->width)
		width_len = base->width - base->precision;
	else
		width_len = base->width - bin_len;
	if (base->flags[3] || base->flags[4])
		width_len -= base->flags[3] + base->flags[4];
	if (base->precision == -1)
		width_len += bin_len;
	precision_len = base->precision > bin_len ? base->precision - bin_len : 0;
	if (base->width && ((!less && base->flags[2]) ||
				(less && !base->flags[2])))
	{
		while (++i <= width_len - precision_len)
			ft_putchar(base->flags[1] && !base->flags[2]
				&& !precision_len ? '0' : ' ');
		base->len += i - 1;
	}
}

static void	ft_print_precision(t_base *base, int bin_len)
{
	int	i;
	int	precision_len;

	i = 0;
	precision_len = (base->precision > bin_len ? base->precision - bin_len : 0);
	if (base->precision)
	{
		while (++i <= precision_len)
			ft_putchar('0');
		base->len += i - 1;
	}
}

void		ft_print_bin(t_base *base, unsigned long long bin)
{
	if (base->width)
		ft_print_width(base, 1, ft_num_len_base(bin, "01"));
	if (base->precision)
		ft_print_precision(base, ft_num_len_base(bin, "01"));
	if (base->precision != -1)
	{
		base->len += ft_num_len_base(bin, "01");
		ft_print_num_base(bin, "01");
	}
	if (base->flags[2])
		ft_print_width(base, 0, ft_num_len_base(bin, "01"));
}
