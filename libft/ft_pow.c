/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:18:18 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/19 14:30:55 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_pow(long double n, int pow)
{
	if (pow < 0)
		return (1 / ft_pow(n, FT_ABS(pow)));
	else
		return (pow ? n * ft_pow(n, pow - 1) : 1);
}
