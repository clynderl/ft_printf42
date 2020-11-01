/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:31:03 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/12 16:33:29 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *last_c;

	last_c = 0;
	while (*s)
	{
		if (*s == (char)c)
			last_c = (char*)s;
		s++;
	}
	if (last_c)
		return (last_c);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
