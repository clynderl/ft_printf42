/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:13:49 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/13 20:48:44 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int pos;

	if (!(*needle))
		return ((char*)haystack);
	pos = 0;
	while (haystack[pos] != '\0' && (size_t)pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i]
			&& (size_t)pos + i < len)
				i++;
			if (needle[i] == '\0')
				return ((char*)&haystack[pos]);
		}
		pos++;
	}
	return (0);
}
