/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:18:57 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/11 19:35:14 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_width(t_base *base, const char *fmt)
{
	base->width = ft_atoi(fmt + base->i);
	base->i += ft_num_len(base->width);
}

void	ft_parse_width_s(t_base *base, int w)
{
	if (w < 0)
	{
		base->flags[2] = '-';
		w *= -1;
	}
	base->width = w;
	base->i++;
}
