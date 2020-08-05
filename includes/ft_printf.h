/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:55:42 by clynderl          #+#    #+#             */
/*   Updated: 2020/08/05 23:00:39 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct	s_base
{
	char		flags[5];
	size_t		width;
	int			precision;
	char		modificator;
	char		conversion;
	size_t		i;
	size_t		len;
}				t_base;

#endif
