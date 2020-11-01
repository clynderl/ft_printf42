/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzoltan <gzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:03:40 by gzoltan           #+#    #+#             */
/*   Updated: 2020/08/14 18:04:13 by gzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsharp(t_base *base)
{
	if (base->conversion == 'x' || base->conversion == 'X'
		|| base->conversion == 'p')
	{
		ft_putstr(base->conversion == 'X' ? "0X" : "0x");
		base->len += 2;
	}
	else if (base->conversion == 'o')
	{
		ft_putchar('0');
		base->len++;
	}
}

int		ft_char_in_str(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
