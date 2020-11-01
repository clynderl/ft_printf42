/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed_neg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:35:30 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/14 15:10:45 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putlnbr(long long int n)
{
	if (n <= LONG_MIN)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (n < 0)
		n = -n;
	if (n > 9)
		ft_putlnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

static void	ft_print_width(t_base *base, int less, int num_len)
{
	int	i;
	int	width_len;
	int	precison_len;

	i = 0;
	if (base->precision > 0 && base->precision < num_len
		&& base->precision > (int)base->width)
		width_len = base->width - base->precision;
	else
		width_len = base->width - num_len;
	if (base->flags[4])
		width_len -= 1;
	if (base->precision == -1)
		width_len += num_len;
	precison_len = base->precision > num_len
		? base->precision - num_len + 1 : 0;
	if (base->flags[4])
		width_len++;
	if (base->width && ((!less && base->flags[2]) ||
				(less && !base->flags[2])))
	{
		while (++i <= width_len - precison_len)
			ft_putchar(base->flags[1] && !base->flags[2] ? '0' : ' ');
		base->len += i - 1;
	}
}

static void	ft_print_precison(t_base *base, int num_len)
{
	int	i;
	int	precison_len;

	i = 0;
	precison_len = base->precision >= num_len
		? base->precision - num_len + 1 : 0;
	if (base->precision)
	{
		while (++i <= precison_len)
			ft_putchar('0');
		base->len += i - 1;
	}
}

void		ft_print_signed_neg(t_base *base, long long int num)
{
	size_t	num_len;

	num_len = ft_num_len(num);
	if (num <= LONG_MIN)
		base->len += 18;
	if (base->precision)
		base->flags[1] = '\0';
	if (base->flags[1])
		ft_putchar('-');
	if (base->width)
		ft_print_width(base, 1, num_len == 2 ? 1 : num_len);
	if (!base->flags[1] && base->precision >= (int)num_len)
		ft_putchar('-');
	if (base->precision && !(base->prec_is_neg))
		ft_print_precison(base, num_len);
	if (!base->flags[1] && base->precision < (int)num_len)
		ft_putchar('-');
	if (base->precision != -1)
	{
		base->len += num_len;
		ft_putlnbr(num);
	}
	if (base->flags[2])
		ft_print_width(base, 0, num_len);
}
