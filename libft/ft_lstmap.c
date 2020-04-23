/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:11:47 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/11/16 01:00:25 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*add;

	if (!lst || !(new = ft_lstnew(f(lst))))
		return (NULL);
	add = new;
	while ((lst = lst->next))
	{
		if (!(new->next = ft_lstnew(f(lst))))
		{
			ft_lstclear(&add, del);
			return (NULL);
		}
		new = new->next;
	}
	new->next = NULL;
	return (add);
}
