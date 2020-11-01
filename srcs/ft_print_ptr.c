/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:46:03 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/14 16:57:43 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_width(t_base *base, int less, int ptr_len)
{
	int	i;
	int	width_len;

	i = 0;
	width_len = base->width - ptr_len;
	if (base->width && ((!less && base->flags[2]) ||
				(less && !base->flags[2])))
	{
		while (++i <= width_len)
			ft_putchar(' ');
		base->len += i - 1;
	}
}

static void	ft_print_precision(t_base *base, int ptr_len)
{
	int	i;
	int	precision_len;

	i = 0;
	precision_len = base->precision > ptr_len ? base->precision - ptr_len : 0;
	if (base->precision)
	{
		while (++i <= precision_len)
			ft_putchar('0');
		base->len += i - 1;
	}
}

void		ft_print_ptr(t_base *base, uintptr_t ptr)
{
	if (ptr == 0 && (base->precision == -1
		|| base->precision < 4) && (base->precision))
	{
		if (base->precision == -1 && (base->len += 2))
			ft_putstr("0x");
		else if (base->precision < 4 && (base->len += 3))
			ft_putstr("0x0");
		return ;
	}
	if (!ptr && ptr != 0)
	{
		ft_putstr("(nil)");
		return ;
	}
	if (base->width)
		ft_print_width(base, 1, ft_num_len_base(ptr, "0123456789abcdef") + 2);
	ft_putstr("0x");
	base->len += 2;
	if (base->precision)
		ft_print_precision(base, ft_num_len_base(ptr, "0123456789abcdef"));
	if (base->precision != -1
		&& (base->len += ft_num_len_base(ptr, "0123456789abcdef")))
		ft_print_num_base(ptr, "0123456789abcdef");
	if (base->width && base->flags[2])
		ft_print_width(base, 0, ft_num_len_base(ptr, "0123456789abcdef") + 2);
}
