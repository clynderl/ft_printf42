/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:01:50 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/16 17:48:04 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	num = n;
	if (n < 0)
		num = n * -1;
	len = ft_getnumsize(num);
	if (n < 0)
		len++;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = num % 10 + '0';
	while (num /= 10)
	{
		str[--len] = num % 10 + '0';
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
