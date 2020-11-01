/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:40:48 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/14 17:01:35 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putlnbr(long long int n)
{
	if (n > 9)
		ft_putlnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

static void	ft_print_width(t_base *base, int less, int num_len)
{
	int	i;
	int	width_len;
	int	precision_len;

	i = 0;
	if (base->precision > 0 && base->precision < num_len
		&& base->precision > (int)base->width)
		width_len = base->width - base->precision;
	else
		width_len = base->width - num_len;
	if (base->flags[3] || base->flags[4])
		width_len -= 1;
	if (base->precision == -1)
		width_len += num_len;
	precision_len = base->precision > num_len ? base->precision - num_len : 0;
	if (base->precision < num_len && (base->precision))
		base->flags[1] = '\0';
	if (base->width && ((!less && base->flags[2]) ||
				(less && !base->flags[2])))
	{
		while (++i <= (width_len - precision_len))
			ft_putchar(base->flags[1] && !base->flags[2]
				&& !precision_len ? '0' : ' ');
		base->len += i - 1;
	}
}

static void	ft_print_precision(t_base *base, int num_len)
{
	int	i;
	int	precision_len;

	i = 0;
	precision_len = (base->precision > num_len ? base->precision - num_len : 0);
	if (base->precision)
	{
		while (++i <= precision_len)
			ft_putchar('0');
		base->len += i - 1;
	}
}

void		ft_print_signed(t_base *base, long long int num)
{
	size_t	num_len;

	num_len = ft_num_len(num);
	if (base->precision && !base->prec_is_neg)
		base->flags[1] = '\0';
	if (base->prec_is_neg)
		base->precision = 0;
	if (base->flags[3] && base->flags[1])
		ft_putchar('+');
	else if (base->flags[4] && !base->flags[3])
	{
		ft_putchar(' ');
		base->len++;
	}
	if (base->width)
		ft_print_width(base, 1, num_len);
	if (base->flags[3] && !base->flags[1])
		ft_putchar('+');
	if (base->precision && !(base->prec_is_neg))
		ft_print_precision(base, num_len);
	if (!(base->precision == -1 && num == 0)
		&& (base->len += (num_len + ft_isascii(base->flags[3]))))
		ft_putlnbr(num);
	if (base->width)
		ft_print_width(base, 0, num_len);
}
