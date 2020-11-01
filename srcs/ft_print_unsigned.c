/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:52:07 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/13 17:59:07 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_width(t_base *base, int less, int num_len)
{
	int	i;
	int	width_len;
	int	precision_len;

	i = 0;
	width_len = (base->width - (base->precision == -1 ? 0 : num_len)) -
		(base->flags[0] && base->conversion != 'u' ? 1 : 0);
	precision_len = base->precision > num_len ? base->precision - num_len : 0;
	if (base->flags[0] && !base->is_zero)
		width_len -= base->conversion == 'x' || base->conversion == 'X' ? 1 : 0;
	if (base->flags[0] && base->is_zero)
		width_len++;
	if (base->width && ((!less && base->flags[2]) ||
				(less && !base->flags[2])))
	{
		while (++i <= width_len - precision_len)
			ft_putchar(base->flags[1] && !base->flags[2] ? '0' : ' ');
		base->len += i - 1;
	}
}

static void	ft_print_precision(t_base *base, int num_len)
{
	int	i;
	int	precision_len;

	i = 0;
	precision_len = base->precision > num_len ? base->precision - num_len : 0;
	if (base->flags[0] && base->conversion == 'o')
		precision_len--;
	if (base->precision)
	{
		while (++i <= precision_len)
			ft_putchar('0');
		base->len += i - 1;
	}
}

static void	ft_print_hex(t_base *base, unsigned long long num)
{
	if (!num)
		base->is_zero = 1;
	if (base->precision)
		base->flags[1] = '\0';
	if (base->flags[0] && num && base->flags[1])
		ft_putsharp(base);
	if (base->width)
		ft_print_width(base, 1, ft_num_len_base(num, "0123456789abcdef"));
	if (base->flags[0] && num && !base->flags[1] && base->precision)
		ft_putsharp(base);
	if (base->precision)
		ft_print_precision(base, ft_num_len_base(num, "0123456789abcdef"));
	if (base->flags[0] && num && !base->flags[1] && !base->precision)
		ft_putsharp(base);
	if (base->precision != -1)
		base->len += ft_num_len_base(num, "0123456789abcdef");
	if (base->conversion == 'x' && base->precision != -1)
		ft_print_num_base(num, "0123456789abcdef");
	else if (base->conversion == 'X' && base->precision != -1)
		ft_print_num_base(num, "0123456789ABCDEF");
	if (base->flags[2])
		ft_print_width(base, 0, ft_num_len_base(num, "0123456789abcdef"));
}

static void	ft_print_oct(t_base *base, unsigned long long num)
{
	if (base->precision)
		base->flags[1] = '\0';
	if (base->width)
		ft_print_width(base, 1, ft_num_len_base(num, "01234567"));
	if (base->precision > 0)
		ft_print_precision(base, ft_num_len_base(num, "01234567"));
	if (base->flags[0])
		ft_putsharp(base);
	if ((num > 0 || base->precision > -1) && !(num == 0 && base->flags[0]))
	{
		base->len += ft_num_len_base(num, "01234567");
		ft_print_num_base(num, "01234567");
	}
	if (base->flags[2])
		ft_print_width(base, 0, ft_num_len_base(num, "01234567"));
}

void		ft_print_unsigned(t_base *base, unsigned long long num)
{
	if (base->conversion == 'x' || base->conversion == 'X')
		ft_print_hex(base, num);
	if (base->conversion == 'o')
		ft_print_oct(base, num);
	if (base->conversion == 'b')
		ft_print_bin(base, num);
	if (base->conversion == 'u')
	{
		if (base->precision)
			base->flags[1] = '\0';
		if (base->width)
			ft_print_width(base, 1, ft_num_len(num));
		if (base->precision)
			ft_print_precision(base, ft_num_len(num));
		if (!(base->precision == -1 && num == 0))
		{
			if (num == ULONG_MAX || (long long)num < 0)
				base->len += 20;
			else
				base->len += ft_num_len(num);
			ft_putulnbr(num);
		}
		if (base->flags[2])
			ft_print_width(base, 0, ft_num_len(num));
	}
}
