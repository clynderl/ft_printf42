/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:55:20 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/14 17:59:27 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long	int		res;
	long	int		res_tmp;
	int				negative;

	negative = 1;
	res = 0;
	res_tmp = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f'))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		if (res < res_tmp && negative == 1)
			return (-1);
		else if (res < res_tmp && negative == -1)
			return (0);
		res_tmp = res;
		str++;
	}
	return (res * negative);
}
