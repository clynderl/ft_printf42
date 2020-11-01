/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:40:08 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/16 17:42:34 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *temp;
	t_list *head;

	temp = *alst;
	head = temp;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
	*alst = head;
}
