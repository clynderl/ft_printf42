/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 03:03:05 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/06 00:09:39 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_init(t_base *base)
{
	ft_bzero(base->flags, 5);
	base->width = 0;
	base->precision = -1;
	base->modificator = '\0';
	base->conversion = '\0';
	base->len = 0;
	base->i = 0;
	return (1);
}

static int	ft_reinit(t_base *base)
{
	ft_bzero(base->flags, 5);
	base->width = 0;
	base->precision = -1;
	base->modificator = '\0';
	base->conversion = '\0';
	return (1);
}

static void	ft_begin(t_base *base, const char *fmt, va_list ap)
{
	while (fmt[base->i])
	{
		if (fmt[base->i] == '%')
		{
			base->i++;
			if (ft_parse(base, fmt))
				ft_process(base, ap);
			ft_reinit(base);
		}
		else
		{
			ft_putchar(fmt[base->i]);
			base->i++;
			base->len++;
		}

	}
}

int			ft_printf(const char *fmt, ...)
{
	t_base	*base;
	size_t	len;
	va_list	ap;

	if (!fmt)
		return (-1);
	if (!(base = malloc(sizeof(t_base))) || !(ft_init(base)))
		return (-1);
	va_start(ap, fmt);
	ft_begin(base, fmt, ap);
	len = base->len;
	free(base);
	return(len);
}
