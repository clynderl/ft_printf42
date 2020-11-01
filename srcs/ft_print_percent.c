/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:49:36 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/11 18:14:14 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_blanks(t_base *base, int less)
{
	int	i;
	int	width_len;

	i = 0;
	width_len = base->width - 1;
	if (base->width && ((less && base->flags[2]) ||
				(!less && !base->flags[2])))
	{
		while (++i <= width_len)
			ft_putchar(base->flags[1] ? '0' : ' ');
		base->len += i - 1;
	}
}

void		ft_print_percent(t_base *base)
{
	if (base->precision)
		base->flags[1] = '\0';
	if (base->flags[2])
		base->flags[1] = '\0';
	if (base->width || base->precision)
		ft_print_blanks(base, 0);
	base->len++;
	ft_putchar('%');
	if (base->flags[2])
		ft_print_blanks(base, 1);
}
