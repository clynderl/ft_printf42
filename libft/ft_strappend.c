/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:24:06 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/14 18:31:31 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend_xo(char **dst, char *s2)
{
	ft_strrealloc(dst, ft_strlen(s2));
	ft_strcpy(*dst + ft_strlen(*dst), s2);
	return (*dst);
}

char	*ft_strappend_xo_chr(char **dst, char c2)
{
	ft_strrealloc(dst, 1);
	dst[0][ft_strlen(*dst)] = c2;
	return (*dst);
}

char	*ft_strappend_xx(char **dst, char **s2)
{
	ft_strrealloc(dst, ft_strlen(*s2));
	ft_strcpy(*dst + ft_strlen(*dst), *s2);
	ft_strdel(s2);
	return (*dst);
}

char	*ft_strappend_ox(char *s2, char **dst)
{
	char *new;

	if (!*dst || !s2)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(*dst) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(new, s2);
	ft_strcat(new, *dst);
	ft_strdel(dst);
	*dst = new;
	return (*dst);
}
