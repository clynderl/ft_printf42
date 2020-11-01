/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnumsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:47:23 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/16 17:52:55 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getnumsize(unsigned int n)
{
	unsigned int size;

	size = 0;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}
