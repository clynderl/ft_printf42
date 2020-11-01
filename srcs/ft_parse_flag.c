/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzoltan <gzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:04:36 by gzoltan           #+#    #+#             */
/*   Updated: 2020/08/14 18:04:41 by gzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flag(t_base *base, const char *fmt)
{
	if (fmt[base->i] == '#')
	{
		base->flags[0] = '#';
		base->i++;
	}
	if (fmt[base->i] == '0')
	{
		base->flags[1] = '0';
		base->i++;
	}
	if (fmt[base->i] == '-')
	{
		base->flags[2] = '-';
		base->i++;
	}
	if (fmt[base->i] == '+')
	{
		base->flags[3] = '+';
		base->i++;
	}
	if (fmt[base->i] == ' ')
	{
		base->flags[4] = ' ';
		base->i++;
	}
}
