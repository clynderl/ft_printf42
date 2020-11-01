/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:06:16 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/14 18:15:24 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*str1;
	const unsigned char	*str2;

	if (!dst && !src && len)
		return (NULL);
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	i = 0;
	if (str2 < str1)
		while (++i <= len)
			str1[len - i] = str2[len - i];
	else
		while (len-- > 0)
			*(str1++) = *(str2++);
	return (dst);
}
