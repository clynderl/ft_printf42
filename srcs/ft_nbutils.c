/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzoltan <gzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:03:19 by gzoltan           #+#    #+#             */
/*   Updated: 2020/08/14 18:03:28 by gzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_num_len(long long int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

void	ft_putulnbr(unsigned long long n)
{
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n > 9)
		ft_putulnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int		ft_num_len_base(long long int nb, char *base)
{
	size_t	i;

	i = 0;
	if ((size_t)nb >= ft_strlen(base))
		i += ft_num_len_base(nb / ft_strlen(base), base);
	i++;
	return (i);
}

void	ft_print_num_base(long long int nb, char *base)
{
	if ((size_t)nb >= ft_strlen(base))
		ft_print_num_base(nb / ft_strlen(base), base);
	ft_putchar(base[nb % ft_strlen(base)]);
}
