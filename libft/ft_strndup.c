/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 05:08:20 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/14 17:16:46 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (src[i] && i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
