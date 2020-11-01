/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:07:22 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/14 10:00:54 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_modify_signed(t_base *base, va_list ap)
{
	long long int	num;

	num = va_arg(ap, long long int);
	if (base->modificator == 'H')
		num = (signed char)num;
	else if (base->modificator == 'h')
		num = (short int)num;
	else if (base->modificator == 'L')
		num = (long long int)num;
	else if (base->modificator == 'l')
		num = (long int)num;
	else
		num = (int)num;
	if (num < 0)
		ft_print_signed_neg(base, num);
	else
		ft_print_signed(base, num);
}

static void	ft_modify_unsigned(t_base *base, va_list ap)
{
	unsigned long long int	num;

	num = va_arg(ap, unsigned long long int);
	if (base->modificator == 'H')
		num = (unsigned char)num;
	else if (base->modificator == 'h')
		num = (unsigned short int)num;
	else if (base->modificator == 'L')
		num = (unsigned long long int)num;
	else if (base->modificator == 'l')
		num = (unsigned long int)num;
	else
		num = (unsigned int)num;
	ft_print_unsigned(base, num);
}

void		ft_process(t_base *base, va_list ap)
{
	if (base->conversion == 'd' || base->conversion == 'i')
		ft_modify_signed(base, ap);
	else if (base->conversion == 'o' || base->conversion == 'u' ||
				base->conversion == 'x' || base->conversion == 'X'
				|| base->conversion == 'b')
		ft_modify_unsigned(base, ap);
	else if (base->conversion == 's')
		ft_print_string(base, va_arg(ap, char *));
	else if (base->conversion == 'c')
		ft_print_char(base, va_arg(ap, int));
	else if (base->conversion == 'p')
		ft_print_ptr(base, va_arg(ap, uintptr_t));
	else if (base->conversion == 'f')
		ft_convert_float(base, ap);
	else if (base->conversion == '%')
		ft_print_percent(base);
}
