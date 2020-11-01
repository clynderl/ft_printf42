/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:45:48 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/13 17:58:50 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*result;
	int		i;

	if (!s || !(result = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	str = (char*)s;
	i = 0;
	while (str[i])
	{
		result[i] = f(str[i]);
		i++;
	}
	return (result);
}
