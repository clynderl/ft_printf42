/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 15:48:34 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/17 17:22:22 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_blanks(t_base *base, int less, int num_len)
{
	int	i;
	int	width_len;

	i = 0;
	if (base->precision > 0 && base->precision < num_len)
		width_len = base->width - base->precision;
	else
		width_len = base->width - num_len;
	if (base->precision == -1)
		width_len += num_len;
	if (base->width && ((!less && base->flags[2]) ||
				(less && !base->flags[2])))
	{
		while (++i <= width_len)
			ft_putchar(' ');
		base->len += i - 1;
	}
}

void		ft_print_char(t_base *base, char c)
{
	if (base->width || base->precision)
		ft_print_blanks(base, 1, 1);
	ft_putchar((char)c);
	if (base->width && base->flags[2])
		ft_print_blanks(base, 0, 1);
	base->len += 1;
}

void		ft_print_string(t_base *base, char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	if (base->precision == 0 || base->prec_is_neg)
		base->precision = 0;
	if (base->width || base->precision)
		ft_print_blanks(base, 1, ft_strlen(str));
	if (base->precision != 0 && base->precision != -1)
	{
		while (i < base->precision && str[i])
			ft_putchar(str[i++]);
		base->len += i;
	}
	else if (base->precision != -1)
	{
		ft_putstr(str);
		base->len += ft_strlen(str);
	}
	if (base->width && base->flags[2])
		ft_print_blanks(base, 0, ft_strlen(str));
}
