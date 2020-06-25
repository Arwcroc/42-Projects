/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:07:28 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/13 19:04:58 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelem;

	if (!lst || !f)
		return (NULL);
	if (!f(lst->content))
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	newlst->next = NULL;
	if (!lst->next)
		return (newlst);
	lst = lst->next;
	while (lst)
	{
		if (!f(lst->content))
		{
			ft_lstclear(&newlst, *del);
			return (NULL);
		}
		newelem = ft_lstnew(f(lst->content));
		ft_lstadd_back(&newlst, newelem);
		lst = lst->next;
	}
	return (newlst);
}
