/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:13:35 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/14 17:39:07 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_whitespace(char s)
{
	if (s && (s == ' ' || s == '\n' || s == '\t'))
		return (1);
	return (0);
}

static	int		is_blank_input(char *s, int *i, size_t *j)
{
	while (is_whitespace(*(s + *i)))
		(*i)++;
	while (is_whitespace(*(s + *j)))
		(*j)--;
	if (*i || *j < ft_strlen(s))
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int			i;
	size_t		j;
	int			k;
	char		*str;
	size_t		size;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	if (!(is_blank_input((char*)s, &i, &j)) || !(ft_strlen(s)))
		return ((char*)s);
	size = (i == (int)ft_strlen(s) ? 0 : (j - i));
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (i <= (int)j)
	{
		str[k] = s[i];
		k++;
		i++;
	}
	return (str);
}
