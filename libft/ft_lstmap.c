/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:28:01 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/14 21:36:56 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;

	if (lst)
	{
		list = f(lst);
		list->next = ft_lstmap(lst->next, f);
		return (list);
	}
	free(lst);
	return (NULL);
}
