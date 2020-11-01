/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:23:17 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/13 18:23:23 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char **ptr, size_t size)
{
	char	*newptr;
	size_t	len;

	len = ft_strlen(*ptr);
	if (!size)
		size = 120;
	if (!(newptr = ft_strnew((len + size) * sizeof(char))))
		return (NULL);
	ft_strcpy(newptr, *ptr);
	free(*ptr);
	*ptr = newptr;
	return (newptr);
}
