/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_modificator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzoltan <gzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:05:02 by gzoltan           #+#    #+#             */
/*   Updated: 2020/08/14 18:05:19 by gzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_modificator(t_base *base, const char *fmt)
{
	if (fmt[base->i] == 'h' && fmt[base->i + 1] == 'h')
		base->modificator = 'H';
	else if (fmt[base->i] == 'h')
		base->modificator = 'h';
	else if (fmt[base->i] == 'l' && fmt[base->i + 1] == 'l')
		base->modificator = 'L';
	else if (fmt[base->i] == 'L')
		base->modificator = 'f';
	else if (fmt[base->i] == 'l')
		base->modificator = 'l';
	if (base->modificator)
		base->i += ft_isupper(base->modificator) ? 2 : 1;
}
