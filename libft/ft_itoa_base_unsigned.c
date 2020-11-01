/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:20:57 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/14 18:31:03 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen_base_unsigned(unsigned long long int n, size_t base)
{
	if (n >= (unsigned long long int)base)
		return (ft_numlen_base_unsigned(n / base, base) + 1);
	return (1);
}

char	*ft_itoa_base_unsigned(unsigned long long int n, int b)
{
	char	*new;
	int		len;
	int		digit;

	len = ft_numlen_base_unsigned(n, b);
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		digit = FT_ABS(n % b);
		new[len] = (digit < 10) ? digit + 48 : digit + 55;
		n /= b;
	}
	return (new);
}
